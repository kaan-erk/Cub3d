#include "../inc/cub3d.h"

void raycast(t_cub *cub)
{
    int x;
    int hit;
    int lineHeight;
    int drawStart;
    int drawEnd;
    double wall_x;
    int tex_x;
    int tex_y;
    double step;
    double tex_pos;
    int tmp;
    t_data *tex;
    char *src;
    char *dst;
    unsigned int color;

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
    tmp = 0;
    tex_y = 0;
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
            if (cub->ray.mapX < 0 || cub->ray.mapX >= cub->game.map_width ||
                cub->ray.mapY < 0 || cub->ray.mapY >= cub->game.map_height)
            {
                hit = 1;
                break;
            }
            if (cub->game.map[cub->ray.mapY][cub->ray.mapX] == '1')
            {
                hit = 1;
                break;
            }
        }
        if (cub->ray.side == 0) // X için
            cub->ray.perpWallDist = (cub->ray.sideDistX - cub->ray.deltaDistX);
        else // Y için
            cub->ray.perpWallDist = (cub->ray.sideDistY - cub->ray.deltaDistY);
        lineHeight = (int)(HEIGHT / cub->ray.perpWallDist);
        
        drawStart = -lineHeight / 2 + HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;

        drawEnd = lineHeight / 2 + HEIGHT / 2;

        if (drawEnd >= HEIGHT)
            drawEnd = HEIGHT - 1;
        
        if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
            cub->ray.text_num = EAST;
        else if (cub->ray.side == 0 && cub->ray.rayDirX < 0)
            cub->ray.text_num = WEST;
        else if (cub->ray.side == 1 && cub->ray.rayDirY > 0)
            cub->ray.text_num = SOUTH;
        else if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
            cub->ray.text_num = NORTH;

        if (cub->ray.side == 0)
            wall_x = cub->player.pos_y + cub->ray.perpWallDist * cub->ray.rayDirY;
        else
            wall_x = cub->player.pos_x + cub->ray.perpWallDist * cub->ray.rayDirX;

        wall_x -= floor(wall_x);

        tex_x = (int)(wall_x * (double)TEX_WIDTH);
        if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
            tex_x = TEX_WIDTH - tex_x - 1;
        if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
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

        tmp = drawStart;
        while (tmp < drawEnd)
        {
            tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
            tex_pos += step;

            src = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
            color = *(unsigned int *)src;

            if (cub->ray.side == 1)
                color = (color >> 1) & 8355711;

            dst = cub->data.addr + (tmp * cub->data.line_len + x * (cub->data.bpp / 8));
            *(unsigned int *)dst = color;

            tmp++;
        }
        x++;    
    }
}
