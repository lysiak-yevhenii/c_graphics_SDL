/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:50:45 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 20:43:20 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*from;

	i = 0;
	dst = (unsigned char*)dest;
	from = (unsigned char*)src;
	while (i < n)
	{
		dst[i] = from[i];
		if (from[i] == (unsigned char)c)
			return ((void*)dest + i + 1);
		i++;
	}
	return (NULL);
}
