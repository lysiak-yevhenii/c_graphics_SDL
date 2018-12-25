/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radius.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 19:53:59 by ylisyak           #+#    #+#             */
/*   Updated: 2018/08/17 19:55:11 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double		ft_radius(int x, int y)
{
	double	radius;

	radius = sqrt(x * x + y * y);
	return (radius);
}
