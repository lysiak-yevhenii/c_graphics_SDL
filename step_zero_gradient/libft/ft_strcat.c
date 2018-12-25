/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:26:49 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 17:03:12 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t			len(char *a)
{
	size_t		i;

	i = 0;
	while (*a++)
		i++;
	return (i);
}

char					*ft_strcat(char *dest, char const *src)
{
	char	*end_dest;
	int		i;

	i = 0;
	end_dest = dest + len(dest);
	while (src[i] != '\0')
	{
		end_dest[i] = (char)src[i];
		i++;
	}
	end_dest[i] = '\0';
	return (dest);
}
