#include "../inc/cub3d.h"

void	raycast(t_cub *cub)
{
	int				x;
	int				hit;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	int				y;
	t_data			*tex;
	char			*src;
	char			*dst;
	unsigned int	color;

	color = 0;
	x = 0;
	hit = 0;
	lineHeight = 0;
	drawStart = 0;
	drawEnd = 0;
	wall_x = 0;
	step = 0;
	(void)tex_pos;
	tex = NULL;
	y = 0;
	tex_y = 0;
	while (x < WIDTH)
	{
		hit = 0;
		cub->ray.camera_x = 2 * x / (double)WIDTH - 1;
		cub->ray.ray_dir_x = cub->player.dir_x + cub->player.plane_x
			* cub->ray.camera_x;
		cub->ray.ray_dir_y = cub->player.dir_y + cub->player.plane_y
			* cub->ray.camera_x;
		cub->ray.map_x = (int)cub->player.pos_x;
		cub->ray.map_y = (int)cub->player.pos_y;
		if (cub->ray.ray_dir_x == 0)
			cub->ray.delta_dist_x = 1e30;
		else
			cub->ray.delta_dist_x = fabs(1 / cub->ray.ray_dir_x);
		if (cub->ray.ray_dir_y == 0)
			cub->ray.delta_dist_y = 1e30;
		else
			cub->ray.delta_dist_y = fabs(1 / cub->ray.ray_dir_y);
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
			if (cub->ray.map_x < 0 || cub->ray.map_x >= cub->game.map_width
				|| cub->ray.map_y < 0 || cub->ray.map_y >= cub->game.map_height)
			{
				hit = 1;
				break ;
			}
			if (cub->game.map[cub->ray.map_y][cub->ray.map_x] == '1')
			{
				hit = 1;
				break ;
			}
		}
		if (cub->ray.side == 0)
			cub->ray.perp_wall_dist = (cub->ray.side_dist_x - cub->ray.delta_dist_x);
		else
			cub->ray.perp_wall_dist = (cub->ray.side_dist_y - cub->ray.delta_dist_y);
		lineHeight = (int)(HEIGHT / cub->ray.perp_wall_dist);
		drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		if (cub->ray.side == 0 && cub->ray.ray_dir_x > 0)
			cub->ray.text_num = EAST;
		else if (cub->ray.side == 0 && cub->ray.ray_dir_x < 0)
			cub->ray.text_num = WEST;
		else if (cub->ray.side == 1 && cub->ray.ray_dir_y > 0)
			cub->ray.text_num = SOUTH;
		else if (cub->ray.side == 1 && cub->ray.ray_dir_y < 0)
			cub->ray.text_num = NORTH;
		if (cub->ray.side == 0)
			wall_x = cub->player.pos_y + cub->ray.perp_wall_dist
				* cub->ray.ray_dir_y;
		else
			wall_x = cub->player.pos_x + cub->ray.perp_wall_dist
				* cub->ray.ray_dir_x;
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * (double)TEX_WIDTH);
		if (cub->ray.side == 0 && cub->ray.ray_dir_x > 0)
			tex_x = TEX_WIDTH - tex_x - 1;
		if (cub->ray.side == 1 && cub->ray.ray_dir_y < 0)
			tex_x = TEX_WIDTH - tex_x - 1;
		step = 1.0 * TEX_HEIGHT / lineHeight;
		tex_pos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
		if (cub->ray.text_num == NORTH)
			tex = &cub->tex_n;
		else if (cub->ray.text_num == SOUTH)
			tex = &cub->tex_s;
		else if (cub->ray.text_num == EAST)
			tex = &cub->tex_e;
		else
			tex = &cub->tex_w;
		y = 0;
		while (y < drawStart)
		{
			dst = cub->data.addr + (y * cub->data.line_len + x * (cub->data.bpp
						/ 8));
			*(unsigned int *)dst = cub->texture.ceiling;
			y++;
		}
		y = drawStart;
		while (y < drawEnd)
		{
			tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
			tex_pos += step;
			src = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
			color = *(unsigned int *)src;
			if (cub->ray.side == 1)
				color = (color >> 1) & 8355711;
			dst = cub->data.addr + (y * cub->data.line_len + x * (cub->data.bpp
						/ 8));
			*(unsigned int *)dst = color;
			y++;
		}
		y = drawEnd;
		while (y < HEIGHT)
		{
			dst = cub->data.addr + (y * cub->data.line_len + x * (cub->data.bpp
						/ 8));
			*(unsigned int *)dst = cub->texture.floor;
			y++;
		}
		x++;
	}
}
