/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:18:18 by ylisyak           #+#    #+#             */
/*   Updated: 2019/01/04 20:05:03 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

t_ray			ft_setray(vector_3 camera, vector_3 point)
{
	t_ray ray;

	ray.camera = camera;
	ray.point = point;
	return (ray);
}

int			ft_iter(t_ray *ray, t_objects *obj, int (*f)(t_ray, t_objects *))
{
	return ((*f)(*ray, obj));
}

int			ft_closer_obj(t_ray ray, t_win *window)
{
	hit_record	tmp_rec;
	int			obj_iter;
	double		hit;
	double		t_closest;
	double		t_max;
	
	hit = 0;
	ray.t_max = 100.0;
	ray.t_min = 0.0;
	obj_iter = 0;	
	while (obj_iter < window->objects_amount - 1)
	{
		ft_iter(&ray, &window->objects[obj_iter], window->objects[obj_iter].inter_fun);
		obj_iter++;
	}
	while (obj_iter--)
	{
		if (window->objects[obj_iter].hit.t < ray.t_max && window->objects[obj_iter].hit.true_fals == 1)
		{
			ray.t_max = window->objects[obj_iter].hit.t;
			window->iter_closer = obj_iter;
			hit = 1;
		}
	}	
	return (hit);
}	

vector_3		ft_color(t_ray ray, t_win	*window)
{
	double		t;

	vector_3	point;
	vector_3	set;

	vector_3 	unit_direction;
	vector_3 	to_return;
	vector_3 	n;
	vector_3	loc;

	set.x = 1.0;
	set.y = 1.0;
	set.z = 1.0;
	point.x = 0.5;
	point.y = 0.7;
	point.z = 1.0;
	if (ft_closer_obj(ray, window))
	{
		t = window->objects[window->iter_closer].hit.t;
		n = ft_unit_vector(ft_subtract_vectors(ft_point_at_parameter(t, ray.camera, ray.point), window->objects[window->iter_closer].pos));
		to_return.x = n.x + 1;
		to_return.y = n.y + 1;
		to_return.z = n.z + 1;
		n = ft_multiply_scalar(to_return, 0.5);
		return (n);
	}
	t = ray.t_max;
	unit_direction = ft_unit_vector(ray.point);
	t = 0.5 * (ray.point.y + 1.0);
	return (ft_add_vectors(ft_multiply_scalar(set, (1.0 - t)), ft_multiply_scalar(point, t))); 
}


void		ft_move(t_win *window)
{
	if (window->currentkeystates[SDL_SCANCODE_W]) 	
		window->objects[4].dir.y += 0.3;
	if (window->currentkeystates[SDL_SCANCODE_S]) 	
		window->objects[4].dir.y -= 0.3;
	if (window->currentkeystates[SDL_SCANCODE_Q]) 	
		window->objects[4].dir.z += 0.3;
	if (window->currentkeystates[SDL_SCANCODE_E]) 	
		window->objects[4].dir.z -= 0.3;
	if (window->currentkeystates[SDL_SCANCODE_D]) 	
		window->objects[4].dir.x += 0.3;
	if (window->currentkeystates[SDL_SCANCODE_A]) 	
		window->objects[4].dir.x -= 0.3;
}


void			ft_core(t_win *window)
{
	float 		u;
	float		v;

	float		r;
	float		g;
	float		b;

	int			x;
	int			y;
	int			dy;
	t_ray		ray;
	vector_3	origin;
	vector_3	vertical;
	vector_3	horizontal;
	vector_3	lower_left_corner;
	
	lower_left_corner.x = -1.0;
    lower_left_corner.y = -0.5;
   	lower_left_corner.z = -0.5;

	vertical.x = 0.0;
	vertical.y = 1.0;      
	vertical.z = 0.0;

	horizontal.x = 2.0;
	horizontal.y = 0.0;
	horizontal.z = 0.0;

	window->operate_surface = SDL_CreateRGBSurface(0, \
			SCREEN_W, SCREEN_H, 32, 0, 0, 0, 0);
	window->operate_pix = window->operate_surface->pixels;
	window->statement = 1;
	while (window->statement)
	{
		if (SDL_WaitEvent(&window->controller))
		{
			(window->controller.type == SDL_QUIT || \
		window->controller.key.keysym.scancode == SDL_SCANCODE_ESCAPE) ? \
							(window->statement = 0) : 0;
		
		window->currentkeystates = SDL_GetKeyboardState(NULL);
		(window->currentkeystates[SDL_SCANCODE_W] || \
		window->currentkeystates[SDL_SCANCODE_S] || \
		window->currentkeystates[SDL_SCANCODE_D] || \
		window->currentkeystates[SDL_SCANCODE_A] ||
			window->currentkeystates[SDL_SCANCODE_E] ||
				window->currentkeystates[SDL_SCANCODE_Q] ) ? ft_move(window) : 0;
		(window->currentkeystates[SDL_SCANCODE_P]) ? (window->statement = 0) : 0;
		}
		x = 0;
		dy = 0;
		y = SCREEN_H - 1;
		while (y >= 0)
		{
			x = 0;
			while (x < SCREEN_W)
			{
				u = (float)x / SCREEN_W;
				v = (float)y / SCREEN_H;
				ray = ft_setray(window->camera.pos, \
				ft_add_vectors(ft_add_vectors(lower_left_corner,\
				ft_multiply_scalar(horizontal, u)),\
				ft_multiply_scalar(vertical, v)));
				vector_3 color = ft_color(ray, window);
				r = color.x * 255.99;
				g = color.y * 255.99;
				b = color.z * 255.99;
				window->operate_pix[x + dy * SCREEN_W] = ft_rgb(b, g, r);
				x++;
			}
			y--;
			dy++;
		}
		SDL_BlitSurface(window->operate_surface, NULL, window->main_surface, NULL);
		SDL_UpdateWindowSurface(window->window);
	
	}
}
