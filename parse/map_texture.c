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

static int	handle_direction_textures(t_cub *cub, int *i)
{
	if (ft_strncmp(cub->game.map_str + *i, "NO ", 3) == 0
		&& cub->texture.n_flag == 0)
		init_texture_north(cub, i);
	else if (ft_strncmp(cub->game.map_str + *i, "SO ", 3) == 0
		&& cub->texture.s_flag == 0)
		init_texture_south(cub, i);
	else if (ft_strncmp(cub->game.map_str + *i, "WE ", 3) == 0
		&& cub->texture.w_flag == 0)
		init_texture_west(cub, i);
	else if (ft_strncmp(cub->game.map_str + *i, "EA ", 3) == 0
		&& cub->texture.e_flag == 0)
		init_texture_east(cub, i);
	else
		return (0);
	return (1);
}

static int	handle_other_textures_and_chars(t_cub *cub, int *i)
{
	if (ft_strncmp(cub->game.map_str + *i, "F ", 2) == 0
		&& cub->texture.f == NULL)
		init_texture_floor(cub, i);
	else if (ft_strncmp(cub->game.map_str + *i, "C ", 2) == 0
		&& cub->texture.c == NULL)
		init_texture_ceiling(cub, i);
	else if (cub->game.map_str[*i] == '\n')
		cub->game.newline_c++;
	else if (cub->game.map_str[*i] == ' ')
		;
	else if (cub->game.map_str[*i] != '1'
		&& cub->game.map_str[*i] != '0'
		&& cub->game.map_str[*i] != '\n')
		exit_free_cub("Error: Wrong texture format", 1, cub);
	else if (cub->game.map_str[*i] == '1')
		return (2);
	else
		return (0);
	return (1);
}

void	cub_texture_allocate(t_cub *cub)
{
	int	i;
	int	len;
	int	ret;

	i = 0;
	if (!cub->game.map_str)
		return ;
	len = ft_strlen(cub->game.map_str);
	while (i < len)
	{
		if (handle_direction_textures(cub, &i))
			;
		else
		{
			ret = handle_other_textures_and_chars(cub, &i);
			if (ret == 2)
				break ;
		}
		i++;
	}
}
