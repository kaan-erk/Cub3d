/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:16:35 by ktoraman          #+#    #+#             */
/*   Updated: 2025/11/26 17:16:55 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	exit_error(char *msg, int i)
{
	ft_putendl_fd(msg, 1);
	exit(i);
}

static void	name_check(char *name)
{
	int	i;
	int	fd;

	i = 0;
	if (name[0] == '\0')
		exit_error("Wrong argument count!", 1);
	while (name[i] != '.')
		i++;
	if (ft_strncmp(name + i, ".cub", 4) == 0 && name[i + 4] == '\0')
	{
		fd = open(name, O_RDONLY);
		if (fd >= 0)
		{
			close(fd);
			return ;
		}
		else
			exit_error("File can not open", 1);
	}
	else
		exit_error("Wrong file name", 1);
}

void	map_checker(char *name)
{
	name_check(name);
}