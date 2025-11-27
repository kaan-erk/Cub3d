/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:42:41 by ktoraman          #+#    #+#             */
/*   Updated: 2025/11/27 16:17:37 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		n_flag;
	int		s_flag;
	int		e_flag;
	int		w_flag;
	char	*f;
	char	*c;
}				t_texture;

typedef struct	s_game
{
	char	**map;
	char	*map_str;
	int		player_c;
	char	player;
}				t_game;


typedef struct	s_cub
{
	t_texture	texture;
	t_game		game;
}				t_cub;

void	map_checker(char *name);
void	parse(char **av);
char	*get_next_line(int fd);

#endif
