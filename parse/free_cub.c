#include "../inc/cub3d.h"

static void	free_map_resources(t_cub *cub)
{
	int	i;

	if (cub->game.map)
	{
		i = 0;
		while (cub->game.map[i])
		{
			free(cub->game.map[i]);
			i++;
		}
		free(cub->game.map);
	}
	if (cub->game.map_str)
		free(cub->game.map_str);
	if (cub->game.real_map_str)
		free(cub->game.real_map_str);
}

void	free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->texture.north)
		free(cub->texture.north);
	if (cub->texture.south)
		free(cub->texture.south);
	if (cub->texture.east)
		free(cub->texture.east);
	if (cub->texture.west)
		free(cub->texture.west);
	if (cub->texture.f)
		free(cub->texture.f);
	if (cub->texture.c)
		free(cub->texture.c);
	free_map_resources(cub);
	free(cub);
}
