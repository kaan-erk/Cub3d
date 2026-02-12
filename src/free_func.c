/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:29:16 by ysoyturk          #+#    #+#             */
/*   Updated: 2026/02/12 20:44:01 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_double(char **double_str)
{
	int	i;

	i = 0;
	if (!double_str)
		return ;
	while (double_str[i])
	{
		free(double_str[i]);
		i++;
	}
	free(double_str);
}
