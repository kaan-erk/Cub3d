/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:11:48 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/19 17:07:49 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	int	i;

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

static int	get_array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static void	check_fc_data(char **f, char **c, t_cub *cub)
{
	int	i;

	if (!f || !c || get_array_len(f) != 3 || get_array_len(c) != 3
		|| !int_check_fc(f, c))
	{
		if (f)
			free_split(f);
		if (c)
			free_split(c);
		exit_free_cub("Error: Floor/Ceiling format or malloc invalid", 1, cub);
	}
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(f[i]) < 0 || ft_atoi(f[i]) > 255
			|| ft_atoi(c[i]) < 0 || ft_atoi(c[i]) > 255)
		{
			free_split(f);
			free_split(c);
			exit_free_cub("Error: RGB values must be 0-255", 1, cub);
		}
	}
}

void	cub_fc_error(t_cub *cub)
{
	char	**f;
	char	**c;

	f = ft_split(cub->texture.f, ',');
	c = ft_split(cub->texture.c, ',');
	check_fc_data(f, c, cub);
	cub->texture.floor = (ft_atoi(f[0]) << 16) | (ft_atoi(f[1]) << 8)
		| ft_atoi(f[2]);
	cub->texture.ceiling = (ft_atoi(c[0]) << 16) | (ft_atoi(c[1]) << 8)
		| ft_atoi(c[2]);
	free_split(f);
	free_split(c);
}
