/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:02:37 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 17:40:34 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *src, size_t n)
{
	char	*from;
	char	*dest;
	size_t	i;

	i = -1;
	from = (char *)src;
	dest = (char *)to;
	if (from < dest)
		while ((int)(--n) >= 0)
			*(dest + n) = *(from + n);
	else
		while (++i < n)
			*(dest + i) = *(from + i);
	return (dest);
}
