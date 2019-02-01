/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:17:27 by ylisyak           #+#    #+#             */
/*   Updated: 2019/01/26 17:57:47 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

int			ft_init_sdl(t_win *window)
{
	(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)	? ft_error_init_window() : 0;
	(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) ? ft_error_render_quality() : 0;
	window->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_CENTERED,\
	SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
	(window->window == NULL) ? ft_error_init_window() : (window->main_surface = SDL_GetWindowSurface(window->window));
	return (1);
}
