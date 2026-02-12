/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:42:41 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/12 20:30:52 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 960
# define HEIGHT 540
# define TITLE "cub3d"
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define KEY_PRESS 2
# define DESTROY 17

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

# define MARGIN 0.2

typedef enum s_tex
{
	EAST,
	NORTH,
	WEST,
	SOUTH
}					t_tex;

typedef struct s_texture
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	int				n_flag;
	int				s_flag;
	int				e_flag;
	int				w_flag;
	char			*f;
	char			*c;
	unsigned int	floor;
	unsigned int	ceiling;
}					t_texture;

typedef struct s_game
{
	char			**map;
	char			*map_str;
	char			*real_map_str;
	int				player_c;
	int				newline_c;
	char			player;
	int				map_width;
	int				map_height;
}					t_game;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_data;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_ray
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	double			perp_wall_dist;
	int				side;
	int				text_num;
	// yenileri
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	double			step;
	double			tex_pos;
}					t_ray;

typedef struct s_cub
{
	t_texture		texture;
	t_game			game;
	t_player		player;
	t_data			data;
	t_data			tex_n;
	t_data			tex_s;
	t_data			tex_e;
	t_data			tex_w;
	t_ray			ray;
}					t_cub;

void				map_checker(char *name, t_cub *cub);
void				parse(char **av, t_cub *cub);
char				*get_next_line(int fd);
void				cub_texture_allocate(t_cub *cub);
void				init_texture_floor(t_cub *cub, int *i);
void				init_texture_ceiling(t_cub *cub, int *i);
void				exit_free_cub(char *msg, int i, t_cub *cub);
void				cub_fc_error(t_cub *cub);
void				cub_texture_error(t_cub *cub);
void				init_cub(t_cub *cub);
void				cub_map_error(t_cub *cub);
void				player_pos(t_cub *cub);
void				player_dir(t_cub *cub);
void				initialize_mlx(t_cub *cub);
void				raycast(t_cub *cub);
int					close_press(t_cub *cub);
void				movement_w(t_cub *cub);
void				movement_s(t_cub *cub);
void				movement_a(t_cub *cub);
void				movement_d(t_cub *cub);
void				rotate_left(t_cub *cub);
void				rotate_right(t_cub *cub);
int					key_press(int key_code, t_cub *cub);
void				free_double(char **double_str);
void				clean_exit(t_cub *cub);
int					game_loop(t_cub *cub);
void				init_ray(t_cub *cub, int x);
void				calc_step(t_cub *cub);
void				perform_dda(t_cub *cub);
void				calc_wall_metrics(t_cub *cub);
void				calc_tex_coords(t_cub *cub);
void				raycast(t_cub *cub);
void				free_double(char **double_str);

#endif
