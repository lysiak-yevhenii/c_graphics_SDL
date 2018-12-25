/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:42:01 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 21:33:53 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *needly)
{
	int		i;
	int		j;
	int		d;

	i = 0;
	if (*needly == '\0')
		return ((char*)s);
	while (s[i] != '\0')
	{
		j = 0;
		d = i;
		while (s[d] == needly[j])
		{
			d++;
			j++;
			if (needly[j] == '\0')
				return ((char*)&s[i]);
		}
		i++;
	}
	return (NULL);
}
