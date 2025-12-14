#include "../inc/cub3d.h"

void player_pos(t_cub *cub)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(cub->game.map[i])
    {
        while(cub->game.map[i][j])
        {
            if (cub->game.map[i][j] == 'N' || cub->game.map[i][j] == 'S' || cub->game.map[i][j] == 'E' || cub->game.map[i][j] == 'W')
            {
                cub->player.pos_y = j + 0.5;
                cub->player.pos_x = i + 0.5;
            }
            j++;
        }
        i++;
        j = 0;
    }
}

void    player_dir(t_cub *cub)
{
    if (cub->game.player == 'N')
    {
        cub->player.dir_x = 0.0;
        cub->player.dir_y = -1.0;
        cub->player.plane_x = 0.66;
        cub->player.plane_y = 0.0;
    }
    else if (cub->game.player == 'S')
    {
        cub->player.dir_x = 0.0;
        cub->player.dir_y = 1.0;
        cub->player.plane_x = -0.66;
        cub->player.plane_y = 0.0;
    }
    else if (cub->game.player == 'E')
    {
        cub->player.dir_x = 1.0;
        cub->player.dir_y = 0.0;
        cub->player.plane_x = 0.0;
        cub->player.plane_y = 0.66;
    }
    else if (cub->game.player == 'W')
    {
        cub->player.dir_x = -1.0;
        cub->player.dir_y = 0.0;
        cub->player.plane_x = 0.0;
        cub->player.plane_y = -0.66;
    }
}
