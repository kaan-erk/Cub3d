/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:11:48 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/23 16:34:42 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	get_array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	count_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

static int	int_check_fc(char **floor, char **ceiling)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = 0;
		if (!floor[i] || !ceiling[i])
			return (0);
		while (floor[i][j])
		{
			if (!(floor[i][j] >= '0' && floor[i][j] <= '9')
				&& floor[i][j] != ' ')
				return (0);
			j++;
		}
		j = -1;
		while (ceiling[i][++j])
		{
			if (!(ceiling[i][j] >= '0' && ceiling[i][j] <= '9')
				&& ceiling[i][j] != ' ')
				return (0);
		}
	}
	return (1);
}

static void	check_fc_data(char **f, char **c, t_cub *cub)
{
	int	i;

	if (get_array_len(f) != 3 || get_array_len(c) != 3 || !int_check_fc(f, c))
	{
		free_split(f);
		free_split(c);
		exit_free_cub("Error: RGB format or invalid characters", 1, cub);
	}
	i = -1;
	while (++i < 3)
	{
		if (ft_atoll(f[i]) < 0 || ft_atoll(f[i]) > 255
			|| ft_atoll(c[i]) < 0 || ft_atoll(c[i]) > 255)
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

	if (count_commas(cub->texture.f) != 2 || count_commas(cub->texture.c) != 2)
		exit_free_cub("Error: RGB must have exactly 2 commas", 1, cub);
	f = ft_split(cub->texture.f, ',');
	c = ft_split(cub->texture.c, ',');
	if (!f || !c)
	{
		free_split(f);
		free_split(c);
		exit_free_cub("Error: Memory allocation failed", 1, cub);
	}
	check_fc_data(f, c, cub);
	cub->texture.floor = (ft_atoi(f[0]) << 16)
		| (ft_atoi(f[1]) << 8) | ft_atoi(f[2]);
	cub->texture.ceiling = (ft_atoi(c[0]) << 16)
		| (ft_atoi(c[1]) << 8) | ft_atoi(c[2]);
	free_split(f);
	free_split(c);
}
