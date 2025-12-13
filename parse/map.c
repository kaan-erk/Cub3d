/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:11:13 by ktoraman          #+#    #+#             */
/*   Updated: 2025/12/08 17:39:45 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	player_check(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->game.real_map_str[i])
	{
		if (cub->game.real_map_str[i] == 'N' || cub->game.real_map_str[i] == 'W'
			|| cub->game.real_map_str[i] == 'E' || cub->game.real_map_str[i] == 'S')
		{
			cub->game.player = cub->game.real_map_str[i];
			cub->game.player_c = 1;
			i++;
			break ;
		}
		i++;
	}
	while (cub->game.real_map_str[i])
	{
		if (cub->game.real_map_str[i] == 'N' || cub->game.real_map_str[i] == 'W'
			|| cub->game.real_map_str[i] == 'E' || cub->game.real_map_str[i] == 'S')
			exit_free_cub("Error: More than one player!", 1, cub);
		i++;
	}
	if (cub->game.player_c != 1)
		exit_free_cub("Error: Missing player!", 1, cub);
}

static void	invalid_character_check(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->game.real_map_str[i])
	{
		if (!(cub->game.real_map_str[i] == 'N' || cub->game.real_map_str[i] == 'W'
			|| cub->game.real_map_str[i] == 'E' || cub->game.real_map_str[i] == 'S'
			|| cub->game.real_map_str[i] == '1' || cub->game.real_map_str[i] == '0'
			|| cub->game.real_map_str[i] == ' ' || cub->game.real_map_str[i] == '\n'))
			exit_free_cub("Error: Invalid character!", 1, cub);
		i++;
	}
	i = 0;
	while (cub->game.real_map_str[i])
	{
		if (cub->game.real_map_str[i] == '\n' && cub->game.real_map_str[i + 1] == '\n')
			exit_free_cub("Error: Extra newline in map!", 1, cub);
		i++;
	}
}

static char	**normalize_map(t_cub *cub)
{
	char	**map_copy;
	int		i;
	int		j;
	int		max_len;

	i = 0;
	max_len = 0;
	while (cub->game.map[i])
	{
		if ((int)ft_strlen(cub->game.map[i]) > max_len)
			max_len = ft_strlen(cub->game.map[i]);
		i++;
	}
	map_copy = ft_calloc(i + 1, sizeof(char *));
	if (!map_copy)
		exit_free_cub("Error: Memory allocation failed\n", 1, cub);
	i = 0;
	while (cub->game.map[i])
	{
		map_copy[i] = ft_calloc(max_len + 1, sizeof(char));
		if (!map_copy[i])
			exit_free_cub("Error: Memory allocation failed\n", 1, cub);
		j = 0;
		while (cub->game.map[i][j])
		{
			map_copy[i][j] = cub->game.map[i][j];
			j++;
		}
		while (j < max_len)
		{
			map_copy[i][j] = '_';
			j++;
		}
		i++;
	}
	return (map_copy);
}

void	find_player_pos(t_cub *cub, char **map_copy, int *px, int *py)
{
	int	i;
	int	j;
	
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == cub->game.player)
			{
				*px = j;
				*py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill_rec(t_cub *cub, char **map_copy, int x, int y)
{
	if (y < 0 || x < 0 || !map_copy[y] || !map_copy[y][x])
	exit_free_cub("Error: Map is not closed!", 1, cub);
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F' || map_copy[y][x] == '_')
	return ;
	if (map_copy[y][x] == ' ')
	exit_free_cub("Error: Map is not closed!", 1, cub);
	map_copy[y][x] = 'F';
	flood_fill_rec(cub, map_copy, x + 1, y);
	flood_fill_rec(cub, map_copy, x - 1, y);
	flood_fill_rec(cub, map_copy, x, y + 1);
	flood_fill_rec(cub, map_copy, x, y - 1);
}

static void	check_unvisited_zero(t_cub *cub, char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == '0')
				exit_free_cub("Error: Unreachable area in map!", 1, cub);
			x++;
		}
		y++;
	}
}

static void	flood_fill(t_cub *cub, char **map_copy)
{
	int	px;
	int	py;

	find_player_pos(cub, map_copy, &px, &py);
	flood_fill_rec(cub, map_copy, px, py);
	check_unvisited_zero(cub, map_copy);
}

static void	map_flood_fill(t_cub *cub)
{
	char	**map_copy;

	map_copy = normalize_map(cub);
	flood_fill(cub, map_copy);
	printf("Normalized Map:\n");
	int i = 0;
	while (map_copy[i])
	{
		printf("%s\n", map_copy[i]);
		i++;
	}
}

void	cub_map_error(t_cub *cub)
{
	player_check(cub);
	invalid_character_check(cub);
	cub->game.map = ft_split(cub->game.real_map_str, '\n');
	if (!cub->game.map)
		exit_free_cub("Error: Memory allocation failed\n", 1, cub);
	map_flood_fill(cub);
}