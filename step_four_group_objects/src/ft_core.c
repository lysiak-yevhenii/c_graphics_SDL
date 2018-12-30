/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:18:18 by ylisyak           #+#    #+#             */
/*   Updated: 2018/12/30 20:32:59 by ylisyak          ###   ########.fr       */
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

void			ft_iter(t_ray ray, t_objects *obj, double (*f)(t_ray, t_objects *))
{
		obj->hit.t = (*f)(ray, obj);
}

double			ft_closer_obj(t_ray ray, t_win *window)
{
	int		obj_iter;
	double	t;
	double	t_closest;

	t_closest = 10;
	obj_iter = 0;
	t = 0;
	while (obj_iter < window->objects_amount - 1)
	{
		ft_iter(ray, &window->objects[obj_iter], window->objects[obj_iter].inter_fun);
		if (t_closest > t)
		{
			t = window->objects[obj_iter].hit.t;
			t_closest = t;
		}
		obj_iter++;
	}	
	return (t_closest);
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
	
	t = ft_closer_obj(ray, window);
	if (t > 0)
	{
		n = ft_unit_vector(ft_subtract_vectors(ft_point_at_parameter(t, ray.camera, ray.point), window->objects[0].pos));
		to_return.x = n.x + 1;
		to_return.y = n.y + 1;
		to_return.z = n.z + 1;
		n = ft_multiply_scalar(to_return, 0.5);
		return (n);
	}
	unit_direction = ft_unit_vector(ray.point);
	t = 0.5 * (ray.point.y + 1.0);
	return (ft_add_vectors(ft_multiply_scalar(set, (1.0 - t)), ft_multiply_scalar(point, t))); 
}


void		ft_move(t_win *window)
{
	if (window->currentkeystates[SDL_SCANCODE_W]) 	
		window->objects[0].pos.y += 0.1;
	if (window->currentkeystates[SDL_SCANCODE_S]) 	
		window->objects[0].pos.y -= 0.1;
	if (window->currentkeystates[SDL_SCANCODE_Q]) 	
		window->objects[0].pos.z += 0.1;
	if (window->currentkeystates[SDL_SCANCODE_E]) 	
		window->objects[0].pos.z -= 0.1;
	if (window->currentkeystates[SDL_SCANCODE_D]) 	
		window->objects[0].pos.x += 0.1;
	if (window->currentkeystates[SDL_SCANCODE_A]) 	
		window->objects[0].pos.x -= 0.1;
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
		}
		window->currentkeystates = SDL_GetKeyboardState(NULL);
		(window->currentkeystates[SDL_SCANCODE_W] || \
		window->currentkeystates[SDL_SCANCODE_S] || \
		window->currentkeystates[SDL_SCANCODE_D] || \
		window->currentkeystates[SDL_SCANCODE_A] ||
			window->currentkeystates[SDL_SCANCODE_E] ||
				window->currentkeystates[SDL_SCANCODE_Q] ) ? ft_move(window) : 0;
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
				ray = ft_setray(window->camera.pos, ft_add_vectors(ft_add_vectors(lower_left_corner, ft_multiply_scalar(horizontal, u)), ft_multiply_scalar(vertical, v)));
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
