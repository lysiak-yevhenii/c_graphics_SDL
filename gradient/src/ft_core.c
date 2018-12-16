/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:18:18 by ylisyak           #+#    #+#             */
/*   Updated: 2018/12/11 01:33:13 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

void		ft_pixel_to_canvas(int x, int y, vector_3 d)
{
	
}

void			ft_core(t_win *window)
{
	float		r;
	float		g;
	float		b;

	int			x;
	int			y;
	int			dy;
	vector_3	o;
	vector_3	d;

	x = 0;
	dy = 0;
	y = SCREEN_H - 1;
	o.x = 0;
	o.y = 0;
	o.z = 0;
	window->operate_surface = SDL_CreateRGBSurface(0, \
			SCREEN_W, SCREEN_H, 32, 0, 0, 0, 0);
	window->operate_pix = window->operate_surface->pixels;
	while (y >= 0)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			r = (float)x / SCREEN_W * 255.99;
			g = (float)y / SCREEN_H * 255.99;	
			b = 0.2 * 255.99;
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
