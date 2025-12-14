#include "../inc/cub3d.h"

void initialize_mlx(t_cub *cub)
{
    cub->data.mlx = mlx_init();
    cub->data.win = mlx_new_window(cub->data.mlx, WIDTH, HEIGHT, TITLE);
    mlx_loop(cub->data.mlx);
}