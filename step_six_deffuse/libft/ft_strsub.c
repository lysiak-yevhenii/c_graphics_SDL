/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:48:06 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/20 16:35:47 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(substr = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s != '\0' && len--)
		{
			substr[i] = (char)s[start];
			i++;
			start++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
