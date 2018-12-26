/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:10:53 by ylisyak           #+#    #+#             */
/*   Updated: 2018/12/26 21:39:54 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

void		ft_print_result_parsing_obj(t_win *window)
{
	int		i;

	i = 0;
		printf("Name: %s\n", window->objects[i].name);
		printf("Location: x = %f, y =  %f, z =  %f \n", window->objects[i].pos.x, window->objects[i].pos.y, window->objects[i].pos.z); 
		printf("Direction: x = %f, y =  %f, z =  %f \n", window->objects[i].dir.x, window->objects[i].dir.y, window->objects[i].dir.z); 
		printf("Color: %d\n", window->objects[i].color);
		printf("Degree: %d\n", window->objects[i].angle);
		printf("Radius: %f\n", window->objects[i].radius);
		printf("\n");
}

int			main(int ac, char **av)
{
	int		objects_mount;
	t_win	window;

	ft_bzero(&window, sizeof(t_win));
	if (ac == 2)
	{
		if ((objects_mount = ft_count_objects(av[1])))
			if (ft_create_objects(&window, objects_mount))
				if (ft_parsing(&window, av[1]))
					if (ft_init_sdl(&window)) 
						ft_core(&window);
		ft_print_result_parsing_obj(&window);
	}
	printf("%f", ft_atoi_double("10"));

	return (0);
}
