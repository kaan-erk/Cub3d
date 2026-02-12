/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:35:19 by ysoyturk          #+#    #+#             */
/*   Updated: 2026/02/12 20:43:37 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_tex_paths(t_cub *cub)
{
	if (cub->texture.north)
		free(cub->texture.north);
	if (cub->texture.south)
		free(cub->texture.south);
	if (cub->texture.west)
		free(cub->texture.west);
	if (cub->texture.east)
		free(cub->texture.east);
	if (cub->texture.f)
		free(cub->texture.f);
	if (cub->texture.c)
		free(cub->texture.c);
}

void	free_map_data(t_cub *cub)
{
	if (cub->game.map)
	{
		free_double(cub->game.map);
		cub->game.map = NULL;
	}
	if (cub->game.map_str)
		free(cub->game.map_str);
	if (cub->game.real_map_str)
		free(cub->game.real_map_str);
}

void	destroy_images(t_cub *cub)
{
	if (cub->tex_n.img)
		mlx_destroy_image(cub->data.mlx, cub->tex_n.img);
	if (cub->tex_s.img)
		mlx_destroy_image(cub->data.mlx, cub->tex_s.img);
	if (cub->tex_e.img)
		mlx_destroy_image(cub->data.mlx, cub->tex_e.img);
	if (cub->tex_w.img)
		mlx_destroy_image(cub->data.mlx, cub->tex_w.img);
	if (cub->data.img)
		mlx_destroy_image(cub->data.mlx, cub->data.img);
}

void	destroy_mlx_core(t_cub *cub)
{
	if (cub->data.win)
		mlx_destroy_window(cub->data.mlx, cub->data.win);
	mlx_destroy_display(cub->data.mlx);
	free(cub->data.mlx);
}

void	clean_exit(t_cub *cub)
{
	if (!cub)
		return ;
	free_tex_paths(cub);
	free_map_data(cub);
	if (cub->data.mlx)
	{
		destroy_images(cub);
		destroy_mlx_core(cub);
	}
	free(cub);
}
