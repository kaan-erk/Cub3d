/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:44:35 by ktoraman          #+#    #+#             */
/*   Updated: 2025/11/27 15:54:44 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void init_cub(t_cub *cub)
{
	if (!cub)
		return;
	cub->texture.north = NULL;
	cub->texture.south = NULL;
	cub->texture.east = NULL;
	cub->texture.west = NULL;
	cub->texture.n_flag = 0;
	cub->texture.s_flag = 0;
	cub->texture.e_flag = 0;
	cub->texture.w_flag = 0;
	cub->texture.f = NULL;
	cub->texture.c = NULL;
	cub->game.map = ft_calloc(1, sizeof(char *));
	if (!cub->game.map)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	cub->game.map[0] = NULL;
	cub->game.map_str = ft_calloc(1, sizeof(char));
	if (!cub->game.map_str)
	{
		free(cub->game.map);
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	cub->game.player_c = 0;
	cub->game.player = 0;
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init_cub(&cub);
	if (ac == 2)
		parse(av, &cub);
	else
		ft_putendl_fd("Error: Wrong argument count!", 2);
}