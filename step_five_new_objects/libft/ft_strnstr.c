/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:15:03 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/21 18:34:45 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t bits)
{
	size_t	lens;

	if (*src == '\0')
		return ((char *)dest);
	lens = ft_strlen(src);
	while (*dest != '\0' && bits-- >= lens)
	{
		if (*dest == *src && ft_memcmp(dest, src, lens) == 0)
			return ((char *)dest);
		dest++;
	}
	return (NULL);
}
