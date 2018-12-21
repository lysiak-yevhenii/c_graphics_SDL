/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:44:56 by ylisyak           #+#    #+#             */
/*   Updated: 2018/08/19 22:02:56 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				itoasize(unsigned int n)
{
	int		i;

	i = 0;
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static unsigned int		ifnegative(int *dig, int *chk, int *len)
{
	unsigned int	newd;

	newd = 0;
	if (*dig < 0)
	{
		*chk = 1;
		newd = (unsigned int)*dig * -1;
		*len = itoasize(newd);
		*len += 1;
		return (newd);
	}
	else if (*dig == 0)
	{
		*len += 1;
		return (*dig);
	}
	else
	{
		*len = itoasize(*dig);
		return (*dig);
	}
}

char					*ft_itoa(int n)
{
	char			*str;
	int				check;
	int				lens;
	unsigned int	g;
	unsigned int	d;

	g = 0;
	check = 0;
	lens = 0;
	d = ifnegative(&n, &check, &lens);
	if (!(str = (char *)malloc(sizeof(char) * (lens + 1))))
		return (NULL);
	str[lens] = '\0';
	while (lens > 0)
	{
		g = d % 10;
		d = d / 10;
		str[--lens] = (char)g + '0';
	}
	if (check == 1)
		str[lens] = '-';
	return (str);
}
