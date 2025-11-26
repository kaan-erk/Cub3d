/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:16:35 by ktoraman          #+#    #+#             */
/*   Updated: 2025/11/26 17:59:45 by ktoraman         ###   ########.fr       */
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

static char	**map_allocate(char *name)
{
	int		fd;
	char	*map_str;
	char	*line;
	char	**map;
	
	map_str = ft_strdup("");
	fd = open(name, O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_str = ft_strjoin(map_str, line);
		free(line);
	}
	close(fd);
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
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
	char	**map;

	name_check(name);
	map = map_allocate(name);// allocation var!
	print_map(map);
}