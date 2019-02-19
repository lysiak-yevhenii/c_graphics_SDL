/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_bpx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:44:18 by ylisyak           #+#    #+#             */
/*   Updated: 2019/02/19 23:30:50 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h" 

void				ft_pixel_put(int x, int y, unsigned int color, t_win *wind)
	{
		
	*((int*)(wind->img2 + ((y * wind->size) + (x * 4)))) = color; 
	//((int*)wind->img2)[y * SCREEN_W + x] = color; 
}

unsigned int		ft_rgb(int r, int g, int b)
{
	unsigned int	result;

	result = 0;
	result = r + (g << 8) + (b << 16);
	return (result);
}
