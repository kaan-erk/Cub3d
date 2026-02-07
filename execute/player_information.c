#include "../inc/cub3d.h"

void	player_pos(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cub->game.map[i])
	{
		while (cub->game.map[i][j])
		{
			if (cub->game.map[i][j] == 'N' || cub->game.map[i][j] == 'S'
				|| cub->game.map[i][j] == 'E' || cub->game.map[i][j] == 'W')
			{
				cub->player.pos_x = j + 0.5;
				cub->player.pos_y = i + 0.5;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	set_direction(t_cub *cub, double dir_x, double dir_y)
{
	cub->player.dir_x = dir_x;
	cub->player.dir_y = dir_y;
}

void	set_plane(t_cub *cub, double plane_x, double plane_y)
{
	cub->player.plane_x = plane_x;
	cub->player.plane_y = plane_y;
}

void	player_dir(t_cub *cub)
{
	if (cub->game.player == 'N')
	{
		set_direction(cub, 0.0, -1.0);
		set_plane(cub, 0.66, 0.0);
	}
	else if (cub->game.player == 'S')
	{
		set_direction(cub, 0.0, 1.0);
		set_plane(cub, -0.66, 0.0);
	}
	else if (cub->game.player == 'E')
	{
		set_direction(cub, 1.0, 0.0);
		set_plane(cub, 0.0, 0.66);
	}
	else if (cub->game.player == 'W')
	{
		set_direction(cub, -1.0, 0.0);
		set_plane(cub, 0.0, -0.66);
	}
}
