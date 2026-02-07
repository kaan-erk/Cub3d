#include "../inc/cub3d.h"

void free_double(char **double_str)
{
    int i;

    i = 0;
    if(!double_str)
        return ;

    while(double_str[i])
    {
        free(double_str[i]);
        i++;
    }
    free(double_str);
}


void	clean_exit(t_cub *cub)
{
	if (!cub)
		return ;

	if (cub->texture.north)
		free(cub->texture.north);
	if (cub->texture.south)
		free(cub->texture.south);
	if (cub->texture.west)
		free(cub->texture.west);
	if (cub->texture.east)
		free(cub->texture.east);
	if (cub->texture.f)
		free(cub->texture.f);
	if (cub->texture.c)
		free(cub->texture.c);
	if (cub->game.map)
    {
		free_double(cub->game.map);
        cub->game.map = NULL;
    }
	if (cub->game.map_str)
		free(cub->game.map_str);
	if (cub->game.real_map_str)
		free(cub->game.real_map_str);

	if (cub->data.mlx)
	{
		if (cub->tex_n.img)
			mlx_destroy_image(cub->data.mlx, cub->tex_n.img);
		if (cub->tex_s.img)
			mlx_destroy_image(cub->data.mlx, cub->tex_s.img);
		if (cub->tex_e.img)
			mlx_destroy_image(cub->data.mlx, cub->tex_e.img);
		if (cub->tex_w.img)
			mlx_destroy_image(cub->data.mlx, cub->tex_w.img);
		if (cub->data.img)
			mlx_destroy_image(cub->data.mlx, cub->data.img);
		
		if (cub->data.win)
			mlx_destroy_window(cub->data.mlx, cub->data.win);
		
		mlx_destroy_display(cub->data.mlx);
		free(cub->data.mlx);
	}

	free(cub);
}