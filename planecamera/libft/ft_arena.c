/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:32:57 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/25 17:44:16 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arena(int size)
{
	char	*area;
	int		i;
	int		j;
	int		sz;

	i = 0;
	j = 1;
	sz = size * (size + 1);
	if (!(area = (char *)malloc(sizeof(char) * sz)))
		return (NULL);
	while (i < (sz - 1))
	{
		if (!(j % (size + 1)) && (i != 0))
		{
			area[i++] = '\n';
			j++;
		}
		area[i] = '.';
		i++;
		j++;
	}
	area[i] = '\0';
	return (area);
}
