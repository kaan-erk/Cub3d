/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:34:16 by ysoyturk          #+#    #+#             */
/*   Updated: 2026/02/12 16:34:16 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	game_loop(t_cub *cub)
{
	raycast(cub);
	mlx_put_image_to_window(cub->data.mlx, cub->data.win, cub->data.img, 0, 0);
	return (0);
}

int	key_press(int key_code, t_cub *cub)
{
	(void)cub;
	if (key_code == W)
		movement_w(cub);
	if (key_code == S)
		movement_s(cub);
	if (key_code == A)
		movement_a(cub);
	if (key_code == D)
		movement_d(cub);
	if (key_code == LEFT)
		rotate_left(cub);
	if (key_code == RIGHT)
		rotate_right(cub);
	if (key_code == ESC)
		close_press(cub);
	return (0);
}

int	close_press(t_cub *cub)
{
	clean_exit(cub);
	exit(0);
	return (0);
}
