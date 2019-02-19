/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 23:54:51 by ylisyak           #+#    #+#             */
/*   Updated: 2019/02/19 20:16:16 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

int				ft_kbuild(int key, t_win *mlx)
{
	(void)key;
	start(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

int			ft_keyboard(int key, t_win *wind)
{
//	if (key == 78 || key == 69)
//	{
//		wind->keyboard = 1;
//		ft_kbuild(key, wind);
//	}
	if (key == 123 || key == 126 || key == 125 || key == 124 || key == 15 || key == 5 || key == 11)
		ft_kbuild(key, wind);
	return (1);
}

void		ft_key_event(t_win *wind)
{
//	mlx_mouse_hook(wind->win, hook_mouse_wheel, wind);
//	mlx_hook(wind->win, 6, 1L << 6, ft_mouse_move, wind);
	mlx_hook(wind->win, 2, 1L << 0, ft_keyboard, wind);
	mlx_hook(wind->win, 17, 1L << 17, exit_x, wind);
}
