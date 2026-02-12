/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:34:55 by ysoyturk          #+#    #+#             */
/*   Updated: 2026/02/12 16:59:17 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_data	*get_texture(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		if (cub->ray.ray_dir_x > 0)
			return (&cub->tex_e);
		return (&cub->tex_w);
	}
	else
	{
		if (cub->ray.ray_dir_y > 0)
			return (&cub->tex_s);
		return (&cub->tex_n);
	}
}

void	draw_wall(t_cub *cub, int x)
{
	int				y;
	int				tex_y;
	unsigned int	color;
	t_data			*tex;

	tex = get_texture(cub);
	y = cub->ray.draw_start;
	while (y < cub->ray.draw_end)
	{
		tex_y = (int)cub->ray.tex_pos & (TEX_HEIGHT - 1);
		cub->ray.tex_pos += cub->ray.step;
		color = *(unsigned int *)(tex->addr + (tex_y * tex->line_len
					+ cub->ray.tex_x * (tex->bpp / 8)));
		if (cub->ray.side == 1)
			color = (color >> 1) & 8355711;
		*(unsigned int *)(cub->data.addr + (y * cub->data.line_len + x
					* (cub->data.bpp / 8))) = color;
		y++;
	}
}

void	draw_bg(t_cub *cub, int x)
{
	int	y;

	y = 0;
	while (y < cub->ray.draw_start)
	{
		*(unsigned int *)(cub->data.addr + (y * cub->data.line_len + x
					* (cub->data.bpp / 8))) = cub->texture.ceiling;
		y++;
	}
	y = cub->ray.draw_end;
	while (y < HEIGHT)
	{
		*(unsigned int *)(cub->data.addr + (y * cub->data.line_len + x
					* (cub->data.bpp / 8))) = cub->texture.floor;
		y++;
	}
}

void	raycast(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(cub, x);
		calc_step(cub);
		perform_dda(cub);
		calc_wall_metrics(cub);
		calc_tex_coords(cub);
		draw_bg(cub, x);
		draw_wall(cub, x);
		x++;
	}
}
