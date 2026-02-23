/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:07:45 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/23 16:35:14 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
