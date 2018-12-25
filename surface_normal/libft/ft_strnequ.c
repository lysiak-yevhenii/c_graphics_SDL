/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:33:29 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/21 19:06:39 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n <= 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (ft_strlen((char*)s1) != ft_strlen((char*)s2))
		return (0);
	if (s1 || s2)
	{
		while ((*s1 || *s2) && n--)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
	}
	return (1);
}
