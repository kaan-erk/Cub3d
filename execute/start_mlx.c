/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:35:02 by ysoyturk          #+#    #+#             */
/*   Updated: 2026/02/12 16:35:03 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_screen_image(t_cub *cub)
{
	cub->data.img = mlx_new_image(cub->data.mlx, WIDTH, HEIGHT);
	cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bpp,
			&cub->data.line_len, &cub->data.endian);
}

void	load_xpm(t_cub *cub, t_data *image, char *path)
{
	int	w;
	int	h;

	image->img = mlx_xpm_file_to_image(cub->data.mlx, path, &w, &h);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->line_len,
			&image->endian);
}

void	init_textures(t_cub *cub)
{
	load_xpm(cub, &cub->tex_n, cub->texture.north);
	load_xpm(cub, &cub->tex_s, cub->texture.south);
	load_xpm(cub, &cub->tex_e, cub->texture.east);
	load_xpm(cub, &cub->tex_w, cub->texture.west);
}

void	initialize_mlx(t_cub *cub)
{
	cub->data.mlx = mlx_init();
	cub->data.win = mlx_new_window(cub->data.mlx, WIDTH, HEIGHT, TITLE);
	init_screen_image(cub);
	init_textures(cub);
	mlx_hook(cub->data.win, DESTROY, 1L << 17, close_press, cub);
	mlx_hook(cub->data.win, KEY_PRESS, 1L << 0, key_press, cub);
	mlx_loop_hook(cub->data.mlx, &game_loop, cub);
	mlx_loop(cub->data.mlx);
}
