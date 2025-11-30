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

void	exit_error(char *msg, int i)
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

void	map_allocate(t_cub *cub)
{
	int	i;
	int	passed_newline;

	i = 0;
	passed_newline = 0;
	while(cub->game.map_str[i] != '\0')
	{
		if (passed_newline == cub->game.newline_c)
			break ;
		else if (cub->game.map_str[i] == '\n')
			passed_newline++;
		i++;
	}
	cub->game.real_map_str = ft_substr(cub->game.map_str, i, ft_strlen(cub->game.map_str) - i);
}

void	map_checker(char *name, t_cub *cub)
{
	name_check(name);
	cub->game.map_str = cub_str_allocate(name);
	cub_texture_allocate(cub);
	map_allocate(cub);
}
