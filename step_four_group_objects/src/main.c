/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:10:53 by ylisyak           #+#    #+#             */
/*   Updated: 2018/12/29 21:32:53 by ylisyak          ###   ########.fr       */
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

		printf("Camera pos x: %f\n", window->camera.pos.x);
		printf("Camera pos y: %f\n", window->camera.pos.y);
		printf("Camera pos z: %f\n", window->camera.pos.z);

}

void		ft_distirbutor(t_win *window)
{
	if (ft_strcmp(window->objects[0].name, "sphere") == 0)
		window->objects[0].inter_fun = sphere;
	else
		printf("Error");	
}

int			main(int ac, char **av)
{
	int		objects_mount;
	t_win	window;

	ft_bzero(&window, sizeof(t_win));
	if (ac == 2)
	{
		if ((window.objects_amount = ft_count_objects(av[1])))
			if (ft_create_objects(&window))
				if (ft_parsing(&window, av[1]))
					if (ft_init_sdl(&window))
					{
						ft_distirbutor(&window);
						ft_core(&window);
					}
			ft_print_result_parsing_obj(&window);
	}
	return (0);
}
