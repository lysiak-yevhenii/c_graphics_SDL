/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:24:58 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 18:07:25 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cs;
	size_t	lens;
	size_t	i;

	i = 0;
	cs = NULL;
	if (s && f)
	{
		lens = ft_strlen((char*)s);
		cs = (char*)malloc(sizeof(char) * (lens + 1));
		if (cs != NULL)
		{
			while (s[i] != 0)
			{
				cs[i] = f(s[i]);
				i++;
			}
			cs[i] = '\0';
			return ((char*)cs);
		}
	}
	return (NULL);
}
