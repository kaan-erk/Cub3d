/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:07:42 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/23 13:55:51 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_texture_north(t_cub *cub, int *i)
{
	int	j;
	int	start;
	int	len;

	j = 0;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j] != '\n' && cub->game.map_str[start
			+ j] != '\0')
		j++;
	len = j;
	while (len > 0 && cub->game.map_str[start + len - 1] == ' ')
		len--;
	cub->texture.north = ft_substr(cub->game.map_str, start, len);
	cub->texture.n_flag = 1;
	*i = start + j;
	cub->game.newline_c++;
}

void	init_texture_south(t_cub *cub, int *i)
{
	int	j;
	int	start;
	int	len;

	j = 0;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j] != '\n' && cub->game.map_str[start
			+ j] != '\0')
		j++;
	len = j;
	while (len > 0 && cub->game.map_str[start + len - 1] == ' ')
		len--;
	cub->texture.south = ft_substr(cub->game.map_str, start, len);
	cub->texture.s_flag = 1;
	*i = start + j;
	cub->game.newline_c++;
}

void	init_texture_west(t_cub *cub, int *i)
{
	int	j;
	int	start;
	int	len;

	j = 0;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j] != '\n' && cub->game.map_str[start
			+ j] != '\0')
		j++;
	len = j;
	while (len > 0 && cub->game.map_str[start + len - 1] == ' ')
		len--;
	cub->texture.west = ft_substr(cub->game.map_str, start, len);
	cub->texture.w_flag = 1;
	*i = start + j;
	cub->game.newline_c++;
}

void	init_texture_east(t_cub *cub, int *i)
{
	int	j;
	int	start;
	int	len;

	j = 0;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j] != '\n' && cub->game.map_str[start
			+ j] != '\0')
		j++;
	len = j;
	while (len > 0 && cub->game.map_str[start + len - 1] == ' ')
		len--;
	cub->texture.east = ft_substr(cub->game.map_str, start, len);
	cub->texture.e_flag = 1;
	*i = start + j;
	cub->game.newline_c++;
}
