/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:48:52 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 21:39:57 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(char *a)
{
	size_t	i;

	i = 0;
	while (*a++)
		i++;
	return (i);
}

char			*ft_strrchr(const char *s, int c)
{
	size_t		lens;

	lens = len((char*)s);
	while (lens != 0 && s[lens] != (char)c)
		lens--;
	if (s[lens] == (char)c)
		return ((char *)&s[lens]);
	return (NULL);
}
