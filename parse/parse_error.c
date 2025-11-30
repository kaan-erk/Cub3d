#include "../inc/cub3d.h"

void    free_cub(t_cub *cub)
{
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
    if (cub->game.map)
    {
        int i = 0;
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

int    is_xpm(char *str)
{
    int len;

    if (!str)
        return (0);
    len = ft_strlen(str);
    if (len < 4)
        return (0);
    if (ft_strncmp(&str[len - 4], ".xpm", 4) == 0)
        return (1);
    return (0);
}

void	exit_free_cub(char *msg, int i, t_cub *cub)
{
    free_cub(cub);
    ft_putendl_fd(msg, 2);
    exit(i);
}

int    is_texture_open(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (0);
    close(fd);
    return (1);
}

void    cub_texture_error(t_cub *cub)
{
    if (cub->texture.n_flag == 0 || cub->texture.s_flag == 0 ||
        cub->texture.e_flag == 0 || cub->texture.w_flag == 0 ||
        cub->texture.f == NULL || cub->texture.c == NULL)
    {
        exit_free_cub("Error: Missing texture information", 1, cub);
    }
    if (!is_xpm(cub->texture.north) || !is_xpm(cub->texture.south) ||
        !is_xpm(cub->texture.east) || !is_xpm(cub->texture.west))
    {
        exit_free_cub("Error: Texture file is not in .xpm format", 1, cub);
    }
    if (is_texture_open(cub->texture.north) == 0 ||
        is_texture_open(cub->texture.south) == 0 ||
        is_texture_open(cub->texture.east) == 0 ||
        is_texture_open(cub->texture.west) == 0)
    {
        exit_free_cub("Error: One or more texture paths are missing", 1, cub);
    }
}
