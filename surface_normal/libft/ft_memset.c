/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:36:44 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 19:47:54 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t nofb)
{
	unsigned char *p;

	p = dest;
	while (nofb--)
		*p++ = (unsigned char)c;
	return (dest);
}
