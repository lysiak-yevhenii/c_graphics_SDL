/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radian_in_degree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 19:48:25 by ylisyak           #+#    #+#             */
/*   Updated: 2018/08/17 19:51:50 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

int		ft_radian_in_degree(double radian)
{
	int	degree;

	degree = 0;
	degree = (radian * 180) / M_PI;
	return (degree);
}
