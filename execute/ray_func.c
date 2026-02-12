/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:54:15 by ysoyturk          #+#    #+#             */
/*   Updated: 2026/02/12 16:54:26 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_ray(t_cub *cub, int x)
{
	cub->ray.camera_x = 2 * x / (double)WIDTH - 1;
	cub->ray.ray_dir_x = cub->player.dir_x + cub->player.plane_x
		* cub->ray.camera_x;
	cub->ray.ray_dir_y = cub->player.dir_y + cub->player.plane_y
		* cub->ray.camera_x;
	cub->ray.map_x = (int)cub->player.pos_x;
	cub->ray.map_y = (int)cub->player.pos_y;
	cub->ray.delta_dist_x = fabs(1 / cub->ray.ray_dir_x);
	cub->ray.delta_dist_y = fabs(1 / cub->ray.ray_dir_y);
}

void	calc_step(t_cub *cub)
{
	if (cub->ray.ray_dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.side_dist_x = (cub->player.pos_x - cub->ray.map_x)
			* cub->ray.delta_dist_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.side_dist_x = (cub->ray.map_x + 1.0 - cub->player.pos_x)
			* cub->ray.delta_dist_x;
	}
	if (cub->ray.ray_dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.side_dist_y = (cub->player.pos_y - cub->ray.map_y)
			* cub->ray.delta_dist_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.side_dist_y = (cub->ray.map_y + 1.0 - cub->player.pos_y)
			* cub->ray.delta_dist_y;
	}
}

void	perform_dda(t_cub *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub->ray.side_dist_x < cub->ray.side_dist_y)
		{
			cub->ray.side_dist_x += cub->ray.delta_dist_x;
			cub->ray.map_x += cub->ray.step_x;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.side_dist_y += cub->ray.delta_dist_y;
			cub->ray.map_y += cub->ray.step_y;
			cub->ray.side = 1;
		}
		if (cub->game.map[cub->ray.map_y][cub->ray.map_x] == '1')
			hit = 1;
	}
}

void	calc_wall_metrics(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.perp_wall_dist = (cub->ray.side_dist_x
				- cub->ray.delta_dist_x);
	else
		cub->ray.perp_wall_dist = (cub->ray.side_dist_y
				- cub->ray.delta_dist_y);
	cub->ray.line_height = (int)(HEIGHT / cub->ray.perp_wall_dist);
	cub->ray.draw_start = -cub->ray.line_height / 2 + HEIGHT / 2;
	if (cub->ray.draw_start < 0)
		cub->ray.draw_start = 0;
	cub->ray.draw_end = cub->ray.line_height / 2 + HEIGHT / 2;
	if (cub->ray.draw_end >= HEIGHT)
		cub->ray.draw_end = HEIGHT - 1;
}

void	calc_tex_coords(t_cub *cub)
{
	double	wall_x;

	if (cub->ray.side == 0)
		wall_x = cub->player.pos_y + cub->ray.perp_wall_dist
			* cub->ray.ray_dir_y;
	else
		wall_x = cub->player.pos_x + cub->ray.perp_wall_dist
			* cub->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	cub->ray.tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if (cub->ray.side == 0 && cub->ray.ray_dir_x > 0)
		cub->ray.tex_x = TEX_WIDTH - cub->ray.tex_x - 1;
	if (cub->ray.side == 1 && cub->ray.ray_dir_y < 0)
		cub->ray.tex_x = TEX_WIDTH - cub->ray.tex_x - 1;
	cub->ray.step = 1.0 * TEX_HEIGHT / cub->ray.line_height;
	cub->ray.tex_pos = (cub->ray.draw_start - HEIGHT / 2 + cub->ray.line_height
			/ 2) * cub->ray.step;
}
