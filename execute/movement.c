#include "../inc/cub3d.h"

void movement_w(t_cub *cub)
{
    double new_x;
    double new_y;

    new_x = cub->player.pos_x + cub->player.dir_x * SPEED;
    new_y = cub->player.pos_y + cub->player.dir_y * SPEED;
    if (cub->game.map[(int)new_y][(int)cub->player.pos_x]  != '1')
        cub->player.pos_x = new_x;
    if (cub->game.map[(int)cub->player.pos_y][(int)new_x] != '1')
        cub->player.pos_y = new_y; 
}

void movement_s(t_cub *cub)
{
    double new_x;
    double new_y;

    new_x = cub->player.pos_x - cub->player.dir_x * SPEED;
    new_y = cub->player.pos_y - cub->player.dir_y * SPEED;
    // if (cub->game.map[(int)new_y][(int)cub->player.pos_x]  != '1')
        cub->player.pos_x = new_x;
    // if (cub->game.map[(int)cub->player.pos_y][(int)new_x] != '1')
        cub->player.pos_y = new_y; 
}

void movement_a(t_cub *cub)
{
    double new_x;
    double new_y;

    new_x = cub->player.pos_x - cub->player.plane_x * SPEED;
    new_y = cub->player.pos_y - cub->player.plane_y * SPEED;
    // if (cub->game.map[(int)new_y][(int)cub->player.pos_x]  != '1')
        cub->player.pos_x = new_x;
    // if (cub->game.map[(int)cub->player.pos_y][(int)new_x] != '1')
        cub->player.pos_y = new_y; 
}

void movement_d(t_cub *cub)
{
    double new_x;
    double new_y;

    new_x = cub->player.pos_x + cub->player.plane_x * SPEED;
    new_y = cub->player.pos_y + cub->player.plane_y * SPEED;
    // if (cub->game.map[(int)new_y][(int)cub->player.pos_x]  != '1')
        cub->player.pos_x = new_x;
    // if (cub->game.map[(int)cub->player.pos_y][(int)new_x] != '1')
        cub->player.pos_y = new_y; 
}