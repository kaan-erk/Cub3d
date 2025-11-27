/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:44:35 by ktoraman          #+#    #+#             */
/*   Updated: 2025/11/27 15:54:44 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		parse(av);
	else
		ft_putstr_fd("Error: Wrong argument count!", 2);
}