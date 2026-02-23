/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:11:13 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/23 15:22:20 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_surrounding_invalid(char **map, int x, int y)
{
	if (y == 0 || x == 0 || !map[y + 1] || !map[y][x + 1])
		return (1);
	if (map[y - 1][x] == ' ' || map[y - 1][x] == '_')
		return (1);
	if (map[y + 1][x] == ' ' || map[y + 1][x] == '_')
		return (1);
	if (map[y][x - 1] == ' ' || map[y][x - 1] == '_')
		return (1);
	if (map[y][x + 1] == ' ' || map[y][x + 1] == '_')
		return (1);
	return (0);
}

static void	mark_playable_areas(char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == '0' || map_copy[y][x] == 'N' ||
				map_copy[y][x] == 'S' || map_copy[y][x] == 'E' ||
				map_copy[y][x] == 'W')
				map_copy[y][x] = 'F';
			x++;
		}
		y++;
	}
}

static void	check_f_surroundings(t_cub *cub, char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'F')
			{
				if (is_surrounding_invalid(map_copy, x, y))
				{
					free_double(map_copy);
					exit_free_cub("Error: Map is not closed!", 1, cub);
				}
			}
			x++;
		}
		y++;
	}
}

static void	validate_map_walls(t_cub *cub)
{
	char	**map_copy;

	map_copy = normalize_map(cub);
	if (!map_copy)
		exit_free_cub("Error: Memory allocation failed", 1, cub);
	mark_playable_areas(map_copy);
	check_f_surroundings(cub, map_copy);
	free_double(map_copy);
}

void	cub_map_error(t_cub *cub)
{
	player_check(cub);
	invalid_character_check(cub);
	cub->game.map = ft_split(cub->game.real_map_str, '\n');
	if (!cub->game.map)
		exit_free_cub("Error: Memory allocation failed", 1, cub);
	validate_map_walls(cub);
}
