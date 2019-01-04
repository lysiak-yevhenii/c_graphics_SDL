/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:12:08 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/21 21:13:09 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		end_dest;

	if (size == 0)
		return (dest);
	i = 0;
	while (dest[i])
		i++;
	end_dest = i;
	while (size > 0 && src[i - end_dest])
	{
		dest[i] = src[i - end_dest];
		i++;
		size--;
	}
	dest[i] = '\0';
	return (dest);
}
