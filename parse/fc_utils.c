/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:07:53 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/19 17:07:54 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_texture_floor(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 1;
	start = *i + 1;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j - 1] != '\n' && cub->game.map_str[start
			+ j - 1] != '\0')
		j++;
	if (cub->texture.f)
		free(cub->texture.f);
	cub->texture.f = ft_substr(cub->game.map_str, start, j - 1);
	*i = start + j - 1;
	cub->game.newline_c++;
}

void	init_texture_ceiling(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 1;
	start = *i + 1;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j - 1] != '\n' && cub->game.map_str[start
			+ j - 1] != '\0')
		j++;
	if (cub->texture.c)
		free(cub->texture.c);
	cub->texture.c = ft_substr(cub->game.map_str, start, j - 1);
	*i = start + j - 1;
	cub->game.newline_c++;
}
