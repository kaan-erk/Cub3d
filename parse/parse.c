/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:15:30 by ktoraman          #+#    #+#             */
/*   Updated: 2025/12/03 20:10:50 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	parse(char **av, t_cub *cub)
{
	char	*name;
	
	name = av[1];
	map_checker(name, cub);
	cub_texture_error(cub);
	cub_fc_error(cub);
	cub_map_error(cub);
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