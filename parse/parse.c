/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:15:30 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/19 17:18:13 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	map_height_width(t_cub *cub)
{
	int	y;

	y = 0;
	while (cub->game.map[y])
		y++;
	cub->game.map_height = y;
	if (y > 0)
		cub->game.map_width = ft_strlen(cub->game.map[0]);
}

void	parse(char **av, t_cub *cub)
{
	char	*name;

	name = av[1];
	map_checker(name, cub);
	cub_texture_error(cub);
	cub_fc_error(cub);
	cub_map_error(cub);
	map_height_width(cub);
}
