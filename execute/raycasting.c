#include "../inc/cub3d.h"

void raycast(t_cub *cub)
{
    int x;

    x = 0;
    while (x < WIDTH)
    {
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
    }
}
