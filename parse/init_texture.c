/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:07:42 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/19 17:07:43 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_texture_north(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 0;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j] != '\n' && cub->game.map_str[start
			+ j] != '\0')
		j++;
	cub->texture.north = ft_substr(cub->game.map_str, start, j);
	cub->texture.n_flag = 1;
	*i = start + j;
	cub->game.newline_c++;
}

void	init_texture_south(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 0;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j] != '\n' && cub->game.map_str[start
			+ j] != '\0')
		j++;
	cub->texture.south = ft_substr(cub->game.map_str, start, j);
	cub->texture.s_flag = 1;
	*i = start + j;
	cub->game.newline_c++;
}

void	init_texture_west(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 0;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j] != '\n' && cub->game.map_str[start
			+ j] != '\0')
		j++;
	cub->texture.west = ft_substr(cub->game.map_str, start, j);
	cub->texture.w_flag = 1;
	*i = start + j;
	cub->game.newline_c++;
}

void	init_texture_east(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 0;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j] != '\n' && cub->game.map_str[start
			+ j] != '\0')
		j++;
	cub->texture.east = ft_substr(cub->game.map_str, start, j);
	cub->texture.e_flag = 1;
	*i = start + j;
	cub->game.newline_c++;
}
