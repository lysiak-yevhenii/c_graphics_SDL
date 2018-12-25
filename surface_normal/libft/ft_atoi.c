/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:41:03 by ylisyak           #+#    #+#             */
/*   Updated: 2018/10/12 17:18:29 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_sdl(const char *s)
{
	int					i;

	i = 0;
	while (*s++)
		if (*s >= '0' && *s <= '9')
			i++;
	return (i);
}

static	void	fill(int *i, int *c, unsigned long long *r)
{
	*i = 0;
	*c = 0;
	*r = 0;
}

int				ft_atoi(const char *nb)
{
	int					i;
	int					c;
	unsigned long long	res;

	fill(&i, &c, &res);
	while (nb[i] == '\t' || nb[i] == '\n' || nb[i] == '\r' ||
			nb[i] == ' ' || nb[i] == '\v' || nb[i] == '\f')
		i++;
	if (nb[i] == '-')
		c = 1;
	if (nb[i] == '-' || nb[i] == '+')
		i++;
	while (nb[i] >= '0' && nb[i] <= '9')
		res = res * 10 + (int)nb[i++] - '0';
	if ((res > 9223372036854775807 && c != 1) || (ft_sdl(nb) >= 19 && c != 1))
		return (-1);
	if (res > 9223372036854775807 && c == 1)
		return (0);
	if (c)
		return (-res);
	return (res);
}
