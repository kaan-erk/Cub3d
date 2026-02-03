/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:44:35 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/03 19:08:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void init_cub(t_cub *cub)
{
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
	cub->game.map = NULL;
	cub->game.map_str = NULL;
	cub->game.real_map_str = NULL;
	cub->game.player_c = 0;
	cub->game.newline_c = 0;
	cub->game.player = 0;
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = ft_calloc(1, sizeof(t_cub));
	if (!cub)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	init_cub(cub);
	if (ac == 2)
		parse(av, cub);
	else
		exit_free_cub("Error: Wrong number of arguments!", 1, cub);
	printf("\n");
	
	// int i = 0;
	// while (cub->game.map[i])
	// {
	// 	printf("%s\n", cub->game.map[i]);
	// 	i++;
	// }

	// ayrı fonksiyonlaştır
	player_pos(cub);
	player_dir(cub);
	initialize_mlx(cub);
	close_press(cub);
	printf("BAŞARILI\n");
}