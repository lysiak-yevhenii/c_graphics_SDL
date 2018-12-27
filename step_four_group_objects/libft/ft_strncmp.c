/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:04:02 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/21 21:12:47 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t bits)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 1;
	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while ((*cs1 || *cs2) && i <= bits && bits > 0)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		cs1++;
		cs2++;
		i++;
	}
	return (0);
}
