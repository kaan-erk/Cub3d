/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:42:41 by ktoraman          #+#    #+#             */
/*   Updated: 2025/12/03 20:13:30 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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
	char	*real_map_str;
	int		player_c;
	int		newline_c;
	char	player;
}				t_game;


typedef struct	s_cub
{
	t_texture	texture;
	t_game		game;
}				t_cub;

void	map_checker(char *name,	 t_cub *cub);
void	parse(char **av, t_cub *cub);
char	*get_next_line(int fd);
void	cub_texture_allocate(t_cub *cub);
void	init_texture_floor(t_cub *cub, int *i);
void	init_texture_ceiling(t_cub *cub, int *i);
void	exit_free_cub(char *msg, int i, t_cub *cub);
void    cub_fc_error(t_cub  *cub);
void	cub_texture_error(t_cub *cub);
void	init_cub(t_cub *cub);
void	cub_map_error(t_cub *cub);

#endif
