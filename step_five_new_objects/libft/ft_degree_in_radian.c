/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degree_in_radian.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 19:49:15 by ylisyak           #+#    #+#             */
/*   Updated: 2018/08/17 19:51:33 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

float		ft_degree_in_radian(int degree)
{
	double	radian;

	radian = 0.0;
	radian = degree * (M_PI / 180);
	return (radian);
}
