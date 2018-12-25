/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 00:43:11 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 18:12:55 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		len(const char *a)
{
	size_t	i;

	i = 0;
	while (*a++)
		i++;
	return (i);
}

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s1_end;

	if (size == 0)
		return (len(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	s1_end = i;
	while (src[i - s1_end] && i < size - 1)
	{
		dst[i] = src[i - s1_end];
		i++;
	}
	if (s1_end < size)
		dst[i] = '\0';
	return (s1_end + len(src));
}
