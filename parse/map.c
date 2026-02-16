/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:11:13 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/12 20:34:31 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	flood_fill_rec(t_cub *cub, char **map_copy, int x, int y)
{
	if (y < 0 || x < 0 || !map_copy[y] || !map_copy[y][x])
	{
		free_double(map_copy);
		exit_free_cub("Error: Map is not closed!", 1, cub);
	}
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F' || map_copy[y][x] == '_')
		return ;
	if (map_copy[y][x] == ' ')
	{
		free_double(map_copy);
		exit_free_cub("Error: Map is not closed!", 1, cub);
	}
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
	int		i;

	map_copy = normalize_map(cub);
	flood_fill(cub, map_copy);
	printf("Normalized Map:\n");
	i = 0;
	while (map_copy[i])
	{
		printf("%s\n", map_copy[i]);
		i++;
	}
	free_double(map_copy);
}

void	cub_map_error(t_cub *cub)
{
	char	**temp_split;

	player_check(cub);
	invalid_character_check(cub);
	temp_split = ft_split(cub->game.real_map_str, '\n');
	cub->game.map = temp_split;
	if (!cub->game.map)
		exit_free_cub("Error: Memory allocation failed\n", 1, cub);
	map_flood_fill(cub);
}
