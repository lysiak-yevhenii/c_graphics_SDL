/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:14:23 by ylisyak           #+#    #+#             */
/*   Updated: 2018/08/17 19:06:56 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*strnew;

	strnew = NULL;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (s1 && s2)
	{
		l = ft_strlen(s1) + ft_strlen(s2);
		if (!(strnew = (char *)malloc(sizeof(char) * (l + 1))))
			return (NULL);
		ft_strcpy(strnew, s1);
		ft_strcat(strnew, s2);
	}
	return (strnew);
}
