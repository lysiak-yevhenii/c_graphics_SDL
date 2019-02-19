/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 23:54:51 by ylisyak           #+#    #+#             */
/*   Updated: 2019/02/19 00:08:44 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

void	ft_keyboard(t_win *window)
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
}
