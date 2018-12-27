/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:24:21 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 18:14:31 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			lens;
	char			*str;

	if (s || f)
	{
		i = 0;
		lens = ft_strlen((char*)s);
		str = (char*)malloc(sizeof(char) * (lens + 1));
		if (str != NULL)
		{
			while (s[i] != '\0')
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
			return ((char*)str);
		}
	}
	return (NULL);
}
