#include "../inc/cub3d.h"

void	player_check(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->game.real_map_str[++i])
	{
		if (cub->game.real_map_str[i] == 'N' || cub->game.real_map_str[i] == 'W'
			|| cub->game.real_map_str[i] == 'E'
			|| cub->game.real_map_str[i] == 'S')
		{
			cub->game.player = cub->game.real_map_str[i];
			cub->game.player_c = 1;
			i++;
			break ;
		}
	}
	while (cub->game.real_map_str[i])
	{
		if (cub->game.real_map_str[i] == 'N' || cub->game.real_map_str[i] == 'W'
			|| cub->game.real_map_str[i] == 'E'
			|| cub->game.real_map_str[i] == 'S')
			exit_free_cub("Error: More than one player!", 1, cub);
		i++;
	}
	if (cub->game.player_c != 1)
		exit_free_cub("Error: Missing player!", 1, cub);
}

void	invalid_character_check(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->game.real_map_str[i])
	{
		if (!(cub->game.real_map_str[i] == 'N'
				|| cub->game.real_map_str[i] == 'W'
				|| cub->game.real_map_str[i] == 'E'
				|| cub->game.real_map_str[i] == 'S'
				|| cub->game.real_map_str[i] == '1'
				|| cub->game.real_map_str[i] == '0'
				|| cub->game.real_map_str[i] == ' '
				|| cub->game.real_map_str[i] == '\n'))
			exit_free_cub("Error: Invalid character!", 1, cub);
		i++;
	}
	i = 0;
	while (cub->game.real_map_str[i])
	{
		if (cub->game.real_map_str[i] == '\n' && cub->game.real_map_str[i
				+ 1] == '\n')
			exit_free_cub("Error: Extra newline in map!", 1, cub);
		i++;
	}
}

void	fill_map_row(char **dest, char *src, int max_len, t_cub *cub)
{
	int	j;

	*dest = ft_calloc(max_len + 1, sizeof(char));
	if (!*dest)
		exit_free_cub("Error: Memory allocation failed\n", 1, cub);
	j = 0;
	while (src[j])
	{
		(*dest)[j] = src[j];
		j++;
	}
	while (j < max_len)
	{
		(*dest)[j] = '_';
		j++;
	}
}

char	**normalize_map(t_cub *cub)
{
	char	**map_copy;
	int		i;
	int		max_len;

	i = 0;
	max_len = 0;
	while (cub->game.map[i])
	{
		if ((int)ft_strlen(cub->game.map[i]) > max_len)
			max_len = ft_strlen(cub->game.map[i]);
		i++;
	}
	map_copy = ft_calloc(i + 1, sizeof(char *));
	if (!map_copy)
		exit_free_cub("Error: Memory allocation failed\n", 1, cub);
	i = -1;
	while (cub->game.map[++i])
		fill_map_row(&map_copy[i], cub->game.map[i], max_len, cub);
	return (map_copy);
}

void	find_player_pos(t_cub *cub, char **map_copy, int *px, int *py)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == cub->game.player)
			{
				*px = j;
				*py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
