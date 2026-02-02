/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:15:30 by ktoraman          #+#    #+#             */
/*   Updated: 2026/02/02 20:19:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void map_height_width(t_cub *cub)
{
	int y = 0;

	while(cub->game.map[y])
		y++;
	cub->game.map_height = y;

	if (y > 0)
		cub->game.map_width = ft_strlen(cub->game.map[0]);
}



void	parse(char **av, t_cub *cub)
{
	char	*name;
	
	name = av[1];
	map_checker(name, cub);
	cub_texture_error(cub);
	cub_fc_error(cub);
	cub_map_error(cub);
	map_height_width(cub);
	/*hepsi silinecek
	printf("After Cub3d Allocation!\n ************** \n");
	printf("%s\n", cub->game.map_str);
	printf("After element Allocation!\n ************** \n");
	printf("North Texture: %s\n", cub->texture.north);
	printf("South Texture: %s\n", cub->texture.south);
	printf("West Texture: %s\n", cub->texture.west);
	printf("East Texture: %s\n", cub->texture.east);
	printf("Floor Texture: %s\n", cub->texture.f);
	printf("Ceiling Texture: %s\n", cub->texture.c);
	printf("********************\n");
	printf("Real Map String:\n%s\n", cub->game.real_map_str);
	*/
}