/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 04:13:44 by ylisyak           #+#    #+#             */
/*   Updated: 2018/11/13 04:15:18 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_nbrlen(int tmpd)
{
	int			len;
	int			res;

	len = 0;
	res = tmpd;
	if (tmpd == 0)
		return (1);
	while (res != 0)
	{
		res = res / 10;
		len++;
	}
	if (len == 0)
		len++;
	if (tmpd < 0)
		len++;
	return (len);
}
