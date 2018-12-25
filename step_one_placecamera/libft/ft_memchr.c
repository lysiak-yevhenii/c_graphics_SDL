/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:15:33 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 16:54:57 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;
	unsigned char	*newptr;

	i = 0;
	ptr = (unsigned char*)dest;
	while (i < (int)n)
	{
		if (*(ptr + i) == (unsigned char)c)
		{
			newptr = ptr + i;
			return (newptr);
		}
		else
		{
			newptr = NULL;
		}
		i++;
	}
	return (newptr);
}
