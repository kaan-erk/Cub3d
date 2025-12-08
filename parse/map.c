/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:11:13 by ktoraman          #+#    #+#             */
/*   Updated: 2025/12/08 17:12:47 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	character_check(t_cub *cub)
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
		}
		i++;
	}
	if (cub->game.player_c != 0)
		exit_free_cub("Error: Invalid character!", 1, cub);
}

void	cub_map_error(t_cub *cub)
{
	character_check(cub);	
}