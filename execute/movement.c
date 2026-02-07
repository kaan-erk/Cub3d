#include "../inc/cub3d.h"

void	movement_w(t_cub *cub)
{
	double	new_x;
	double	new_y;
	double	offset_y;
	double	offset_x;

	new_x = cub->player.pos_x + cub->player.dir_x * MOVE_SPEED;
	new_y = cub->player.pos_y + cub->player.dir_y * MOVE_SPEED;
	if (cub->player.dir_y > 0)
		offset_y = MARGIN;
	else
		offset_y = -MARGIN;
	if (cub->player.dir_x > 0)
		offset_x = MARGIN;
	else
		offset_x = -MARGIN;
	if (cub->game.map[(int)(new_y + offset_y)][(int)cub->player.pos_x] != '1')
		cub->player.pos_y = new_y;
	if (cub->game.map[(int)cub->player.pos_y][(int)(new_x + offset_x)] != '1')
		cub->player.pos_x = new_x;
}

void	movement_s(t_cub *cub)
{
	double	new_x;
	double	new_y;
	double	offset_y;
	double	offset_x;

	if (cub->player.dir_y > 0)
		offset_y = -MARGIN;
	else
		offset_y = MARGIN;
	if (cub->player.dir_x > 0)
		offset_x = -MARGIN;
	else
		offset_x = MARGIN;
	new_x = cub->player.pos_x - cub->player.dir_x * MOVE_SPEED;
	new_y = cub->player.pos_y - cub->player.dir_y * MOVE_SPEED;
	if (cub->game.map[(int)(new_y + offset_y)][(int)cub->player.pos_x] != '1')
		cub->player.pos_y = new_y;
	if (cub->game.map[(int)cub->player.pos_y][(int)(new_x + offset_x)] != '1')
		cub->player.pos_x = new_x;
}

void	movement_a(t_cub *cub)
{
	double	new_x;
	double	new_y;
	double	offset_y;
	double	offset_x;

	if (cub->player.plane_y > 0)
		offset_y = -MARGIN;
	else
		offset_y = MARGIN;
	if (cub->player.plane_x > 0)
		offset_x = -MARGIN;
	else
		offset_x = MARGIN;
	new_x = cub->player.pos_x - cub->player.plane_x * MOVE_SPEED;
	new_y = cub->player.pos_y - cub->player.plane_y * MOVE_SPEED;
	if (cub->game.map[(int)(new_y + offset_y)][(int)cub->player.pos_x] != '1')
		cub->player.pos_y = new_y;
	if (cub->game.map[(int)cub->player.pos_y][(int)(new_x + offset_x)] != '1')
		cub->player.pos_x = new_x;
}

void	movement_d(t_cub *cub)
{
	double	new_x;
	double	new_y;
	double	offset_y;
	double	offset_x;

	if (cub->player.plane_y > 0)
		offset_y = MARGIN;
	else
		offset_y = -MARGIN;
	if (cub->player.plane_x > 0)
		offset_x = MARGIN;
	else
		offset_x = -MARGIN;
	new_x = cub->player.pos_x + cub->player.plane_x * MOVE_SPEED;
	new_y = cub->player.pos_y + cub->player.plane_y * MOVE_SPEED;
	if (cub->game.map[(int)(new_y + offset_y)][(int)cub->player.pos_x] != '1')
		cub->player.pos_y = new_y;
	if (cub->game.map[(int)cub->player.pos_y][(int)(new_x + offset_x)] != '1')
		cub->player.pos_x = new_x;
}
