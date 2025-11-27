/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:16:35 by ktoraman          #+#    #+#             */
/*   Updated: 2025/11/27 15:58:02 by ktoraman         ###   ########.fr       */
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
		exit_error("Error: Names is NULL!", 1);
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
			exit_error("Error: File can not open", 1);
	}
	else
		exit_error("Error: Wrong file name", 1);
}

static char	*cub_str_allocate(char *name)
{
	int		fd;
	char	*cub_str;
	char	*line;
	
	cub_str = ft_strdup("");
	fd = open(name, O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cub_str = ft_strjoin(cub_str, line);
		free(line);
	}
	close(fd);
	return (cub_str);
}

void	print_map(char **map)//printer sil
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}


void	map_checker(char *name)
{
	char	*cub_str;

	name_check(name);
	cub_str = cub_str_allocate(name);// allocation var!
	printf("After Cub3d Allocation!\n ************** \n");
	printf("%s", cub_str);
}