/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:11:54 by ktoraman          #+#    #+#             */
/*   Updated: 2025/12/03 20:11:55 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_texture_north(t_cub *cub, int *i)
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

static void	init_texture_south(t_cub *cub, int *i)
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

static void	init_texture_west(t_cub *cub, int *i)
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

static void	init_texture_east(t_cub *cub, int *i)
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

void    cub_texture_allocate(t_cub *cub)
{
    int i;
    int len;

    i = 0;
    if (!cub->game.map_str)
        return ;
    len = ft_strlen(cub->game.map_str);
    while (i < len)
    {
        if (ft_strncmp(cub->game.map_str + i, "NO ", 3) == 0
            && cub->texture.n_flag == 0)
            init_texture_north(cub, &i);
        else if (ft_strncmp(cub->game.map_str + i, "SO ", 3) == 0
            && cub->texture.s_flag == 0)
            init_texture_south(cub, &i);
        else if (ft_strncmp(cub->game.map_str + i, "WE ", 3) == 0
            && cub->texture.w_flag == 0)
            init_texture_west(cub, &i);
        else if (ft_strncmp(cub->game.map_str + i, "EA ", 3) == 0
            && cub->texture.e_flag == 0)
            init_texture_east(cub, &i);
        else if (ft_strncmp(cub->game.map_str + i, "F ", 2) == 0
            && cub->texture.f == NULL)
            init_texture_floor(cub, &i);
        else if (ft_strncmp(cub->game.map_str + i, "C ", 2) == 0
            && cub->texture.c == NULL)
            init_texture_ceiling(cub, &i);
        else if (cub->game.map_str[i] == '\n')
            cub->game.newline_c++;
        else if (cub->game.map_str[i] == ' ')
            ;
        else if (cub->game.map_str[i] != '1' && cub->game.map_str[i] != '0'
            && cub->game.map_str[i] != '\n')
            exit_free_cub("Error: Wrong texture format", 1, cub);
        else if (cub->game.map_str[i] == '1')
            break ;
        i++;
    }
}
