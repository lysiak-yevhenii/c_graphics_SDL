/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:18:18 by ylisyak           #+#    #+#             */
/*   Updated: 2018/12/16 18:52:08 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

void		ft_pixel_to_canvas(int x, int y, vector_3 d)
{
	
}


t_ray			ft_setray(vector_3 camera, vector_3 point)
{
	t_ray ray;

	ray.camera = camera;
	ray.point = point;
	return (ray);
}

vector_3		ft_color(t_ray ray)
{
	float		t;
	vector_3	point;
	vector_3	set;
	vector_3 	unit_direction;

	set.x = 1.0;
	set.y = 1.0;
	set.z = 1.0;
	point.x = 0.5;
	point.y = 0.7;
	point.z = 1.0;
	unit_direction = ft_unit_vector(ray.point);
	t = 0.5 * (ray.point.y + 1.0);
	return (ft_add_vectors(ft_multiply_scalar(set, (1.0 - t)), ft_multiply_scalar(point, t))); 
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
	
	lower_left_corner.x = -2.0;
    lower_left_corner.y = -1.0;
   	lower_left_corner.z = -1.0;

	origin.x = 0.0;
	origin.y = 0.0;
	origin.z = 0.0;

	vertical.x = 0.0;
	vertical.y = 4.0;      
	vertical.z = 0.0;

	horizontal.x = 1.0;
	horizontal.y = 0.0;
	horizontal.z = 0.0;

	window->operate_surface = SDL_CreateRGBSurface(0, \
			SCREEN_W, SCREEN_H, 32, 0, 0, 0, 0);
	window->operate_pix = window->operate_surface->pixels;
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
			ray = ft_setray(origin, ft_add_vectors(ft_add_vectors(lower_left_corner, ft_multiply_scalar(horizontal, u)), ft_multiply_scalar(vertical, v)));
			vector_3 color = ft_color(ray);
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
	SDL_Delay(10000);
}
