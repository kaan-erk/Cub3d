#include "../inc/cub3d.h"

void raycast(t_cub *cub)
{
    int x;
    int hit;
    
    x = 0;
    hit = 0;
    while (x < WIDTH)
    {
        hit = 0;
        cub->ray.camera_x = 2 * x / (double)WIDTH - 1;
        cub->ray.rayDirX = cub->player.dir_x + cub->player.plane_x * cub->ray.camera_x;
        cub->ray.rayDirY = cub->player.dir_y + cub->player.plane_y * cub->ray.camera_x;
        cub->ray.mapX = (int)cub->player.pos_x;
        cub->ray.mapY = (int)cub->player.pos_y;
        if (cub->ray.rayDirX == 0)
            cub->ray.deltaDistX = 1e30;
        else 
            cub->ray.deltaDistX = fabs(1 / cub->ray.rayDirX);
        if (cub->ray.rayDirY == 0)
            cub->ray.deltaDistY = 1e30;
        else 
            cub->ray.deltaDistY = fabs(1 / cub->ray.rayDirY);
        if (cub->ray.rayDirX < 0)
        {
            cub->ray.stepX = -1;
            cub->ray.sideDistX = (cub->player.pos_x - cub->ray.mapX) * cub->ray.deltaDistX;
        }
        else
        {
            cub->ray.stepX = 1;
            cub->ray.sideDistX = (cub->ray.mapX + 1.0 - cub->player.pos_x) * cub->ray.deltaDistX;
        }
        if (cub->ray.rayDirY < 0)
        {
            cub->ray.stepY = -1;
            cub->ray.sideDistY = (cub->player.pos_y - cub->ray.mapY) * cub->ray.deltaDistY;
        }
        else
        {
            cub->ray.stepY = 1;
            cub->ray.sideDistY = (cub->ray.mapY + 1.0 - cub->player.pos_y) * cub->ray.deltaDistY;
        }

        while (hit == 0)
        {
            if (cub->ray.sideDistX < cub->ray.sideDistY)
            {
                cub->ray.sideDistX += cub->ray.deltaDistX;
                cub->ray.mapX += cub->ray.stepX;
                cub->ray.side = 0;
            }
            else 
            {
                cub->ray.sideDistY += cub->ray.deltaDistY;
                cub->ray.mapY += cub->ray.stepY;
                cub->ray.side = 1;
            }
            if (cub->game.map[cub->ray.mapY][cub->ray.mapX] != 0)
                hit = 1;
            
        }
    }
}
