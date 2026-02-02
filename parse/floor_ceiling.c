/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:11:48 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/03 00:13:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (cub->texture.f)
		free(cub->texture.f);
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
	if (cub->texture.c)
		free(cub->texture.c);
	cub->texture.c = ft_substr(cub->game.map_str, start, j - 1);
	*i = start + j - 1;
	cub->game.newline_c++;
}

static int	int_check_fc(char **floor, char **ceiling)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		if (!floor[i] || !ceiling[i])
			return (0);
		while (floor[i][j])
		{
			if (!('0' <= floor[i][j] && '9' >= floor[i][j]))
				return (0);
			j++;
		}
		j = 0;
		while (ceiling[i][j])
		{
			if (!('0' <= ceiling[i][j] && '9' >= ceiling[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	free_split(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int get_array_len(char **arr)
{
    int i = 0;
    while (arr[i])
        i++;
    return (i);
}

void    cub_fc_error(t_cub *cub)
{
    int     i;
    char    **temp_floor;
    char    **temp_ceiling;

    temp_floor = ft_split(cub->texture.f, ',');
    temp_ceiling = ft_split(cub->texture.c, ',');
    if (!temp_floor || !temp_ceiling)
    {
        free_split(temp_floor);
        free_split(temp_ceiling);
        exit_free_cub("Error: Memory allocation failed", 1, cub);
    }

    if (get_array_len(temp_floor) != 3 || get_array_len(temp_ceiling) != 3)
    {
        free_split(temp_floor);
        free_split(temp_ceiling);
        exit_free_cub("Error: Floor or Ceiling must have 3 components (R,G,B)!", 1, cub);
    }

    if (!int_check_fc(temp_floor, temp_ceiling))
    {
        free_split(temp_floor);
        free_split(temp_ceiling);
        exit_free_cub("Error: Floor/Ceiling contains non-numeric characters!", 1, cub);
    }

    i = 0;
    while (i < 3)
    {
        int f_val = ft_atoi(temp_floor[i]);
        int c_val = ft_atoi(temp_ceiling[i]);

        if (f_val < 0 || f_val > 255 || c_val < 0 || c_val > 255)
        {
            free_split(temp_floor);
            free_split(temp_ceiling);
            exit_free_cub("Error: RGB values must be between 0 and 255!", 1, cub);
        }
        i++;
    }

    cub->texture.floor = (ft_atoi(temp_floor[0]) << 16) | 
                       (ft_atoi(temp_floor[1]) << 8) | 
                       ft_atoi(temp_floor[2]);

    cub->texture.ceiling = (ft_atoi(temp_ceiling[0]) << 16) | 
                         (ft_atoi(temp_ceiling[1]) << 8) | 
                         ft_atoi(temp_ceiling[2]);

    free_split(temp_floor);
    free_split(temp_ceiling);
}

