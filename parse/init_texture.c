#include "../inc/cub3d.h"

void	init_texture_north(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 3;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j - 3] != '\n' && cub->game.map_str[start
			+ j - 3] != '\0')
		j++;
	cub->texture.north = ft_substr(cub->game.map_str, start, j - 3);
	cub->texture.n_flag = 1;
	*i = start + j - 3;
	cub->game.newline_c++;
}

void	init_texture_south(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 3;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j - 3] != '\n' && cub->game.map_str[start
			+ j - 3] != '\0')
		j++;
	cub->texture.south = ft_substr(cub->game.map_str, start, j - 3);
	cub->texture.s_flag = 1;
	*i = start + j - 3;
	cub->game.newline_c++;
}

void	init_texture_west(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 3;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j - 3] != '\n' && cub->game.map_str[start
			+ j - 3] != '\0')
		j++;
	cub->texture.west = ft_substr(cub->game.map_str, start, j - 3);
	cub->texture.w_flag = 1;
	*i = start + j - 3;
	cub->game.newline_c++;
}

void	init_texture_east(t_cub *cub, int *i)
{
	int	j;
	int	start;

	j = 3;
	start = *i + 3;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j - 3] != '\n' && cub->game.map_str[start
			+ j - 3] != '\0')
		j++;
	cub->texture.east = ft_substr(cub->game.map_str, start, j - 3);
	cub->texture.e_flag = 1;
	*i = start + j - 3;
	cub->game.newline_c++;
}
