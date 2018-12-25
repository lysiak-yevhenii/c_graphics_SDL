/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_bpx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:44:18 by ylisyak           #+#    #+#             */
/*   Updated: 2018/12/11 02:01:43 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h" 

void				ft_draw_bpx(int x, int y, size_t color, SDL_Surface *img)
{
	*((unsigned int *)(img->pixels + y * img->pitch + x *\
				img->format->BytesPerPixel)) = color;
}

unsigned int		ft_rgb(int r, int g, int b)
{
	unsigned int	result;

	result = 0;
	result = r + (g << 8) + (b << 16);
	return (result);
}
