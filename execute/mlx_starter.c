#include "../inc/cub3d.h"

void init_screen_image(t_cub *cub)
{
    cub->data.img = mlx_new_image(cub->data.mlx, WIDTH, HEIGHT);
    
    // if (!cub->data.img)
    //     return (-1);
    cub->data.addr = mlx_get_data_addr(cub->data.img, 
                                       &cub->data.bpp, 
                                       &cub->data.line_len, 
                                       &cub->data.endian);
}

void load_xpm(t_cub *cub, t_data *image, char *path)
{
    int w;
    int h;

    image->img = mlx_xpm_file_to_image(cub->data.mlx, path, &w, &h);
    // if (!image->img)
    //     return (-1);

    image->addr = mlx_get_data_addr(image->img, 
                                    &image->bpp, 
                                    &image->line_len, 
                                    &image->endian);
}

void init_textures(t_cub *cub)
{
    load_xpm(cub, &cub->tex_n, cub->texture.north); 
    load_xpm(cub, &cub->tex_s, cub->texture.south);
    load_xpm(cub, &cub->tex_e, cub->texture.east);
    load_xpm(cub, &cub->tex_w, cub->texture.west);
}

int game_loop(t_cub *cub)
{
    raycast(cub);
    mlx_put_image_to_window(cub->data.mlx, cub->data.win, cub->data.img, 0, 0);

    return (0);
}

void initialize_mlx(t_cub *cub)
{
    cub->data.mlx = mlx_init();
    cub->data.win = mlx_new_window(cub->data.mlx, WIDTH, HEIGHT, TITLE);
    init_screen_image(cub);
    init_textures(cub);
    mlx_loop_hook(cub->data.mlx, &game_loop, cub);
    mlx_loop(cub->data.mlx);
}