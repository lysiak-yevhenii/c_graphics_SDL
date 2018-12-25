/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:15:04 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/15 21:37:49 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strlen((char*)s1) != ft_strlen((char*)s2))
		return (0);
	if (s1 || s2)
	{
		while (*s1 && *s2)
		{
			if (*s2 != *s1)
				return (0);
			s1++;
			s2++;
		}
	}
	return (1);
}
