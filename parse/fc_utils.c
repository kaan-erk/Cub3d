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
	int	start;
	int	len;
	int	real_len;

	start = *i + 1;
	while (cub->game.map_str[start] == ' ')
		start++;
	len = 0;
	while (cub->game.map_str[start + len] && cub->game.map_str[start + len] != '\n')
		len++;
	*i = start + len;
	real_len = len;
	while (real_len > 0 && cub->game.map_str[start + real_len - 1] == ' ')
		real_len--;
	if (cub->texture.f)
		free(cub->texture.f);
	cub->texture.f = ft_substr(cub->game.map_str, start, real_len);
	cub->game.newline_c++;
}

void	init_texture_ceiling(t_cub *cub, int *i)
{
	int	start;
	int	len;
	int	real_len;

	start = *i + 1;
	while (cub->game.map_str[start] == ' ')
		start++;
	len = 0;
	while (cub->game.map_str[start + len] && cub->game.map_str[start + len] != '\n')
		len++;
	*i = start + len;
	real_len = len;
	while (real_len > 0 && cub->game.map_str[start + real_len - 1] == ' ')
		real_len--;
	if (cub->texture.c)
		free(cub->texture.c);
	cub->texture.c = ft_substr(cub->game.map_str, start, real_len);
	cub->game.newline_c++;
}
