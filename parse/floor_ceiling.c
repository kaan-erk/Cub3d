#include "../inc/cub3d.h"

void    init_texture_floor(t_cub *cub, int *i)
{
	int j;
	int start;

	j = 1;
	start = *i + 1;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j - 1] != '\n' && cub->game.map_str[start + j -1] != '\0')
		j++;
	cub->texture.f = ft_substr(cub->game.map_str, start, j - 1);
	*i = start + j - 1;
	cub->game.newline_c++;

}

void    init_texture_ceiling(t_cub *cub, int *i)
{
	int j;
	int start;

	j = 1;
	start = *i + 1;
	while (cub->game.map_str[start] == ' ')
		start++;
	while (cub->game.map_str[start + j - 1] != '\n' && cub->game.map_str[start + j -1] != '\0')
		j++;
	cub->texture.c = ft_substr(cub->game.map_str, start, j - 1);
	*i = start + j - 1;
	cub->game.newline_c++;
}

void	int_check_fc(char **floor, char **ceiling, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (floor[i][j])
		{
			if (!('0' <= floor[i][j] && '9' >= floor[i][j]))
				exit_free_cub("Error: Something wrong with floor!", 1, cub);
			j++;
		}
		j = 0;
		while (ceiling[i][j])
		{
			if (!('0' <= ceiling[i][j] && '9' >= ceiling[i][j]))
				exit_free_cub("Error: Something wrong with ceiling!", 1, cub);
			j++;
		}
		i++;
	}
}

void	cub_fc_error(t_cub  *cub)
{
	int		i;
	char	**temp_floor;
	char	**temp_ceiling;

	i = 0;
	temp_floor = ft_split(cub->texture.f, ',');
	temp_ceiling = ft_split(cub->texture.c, ',');
	if (temp_floor[3] != NULL)
		exit_free_cub("Error: Something wrong with floor!", 1, cub);
	if (temp_ceiling[3] != NULL)
		exit_free_cub("Error: Something wrong with ceiling!", 1, cub);
	int_check_fc(temp_floor, temp_ceiling, cub);
	while (i < 3)
	{
		if (!(0 <= ft_atoi(temp_floor[i]) && ft_atoi(temp_floor[i]) <= 255))
			exit_free_cub("Error: Something wrong with floor!", 1, cub);
		if (!(0 <= ft_atoi(temp_floor[i]) && ft_atoi(temp_floor[i]) <= 255))
			exit_free_cub("Error: Something wrong with ceiling!", 1, cub);
		i++;
	}
}
