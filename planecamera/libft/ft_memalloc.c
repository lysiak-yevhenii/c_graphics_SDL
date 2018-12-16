/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:18:54 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/22 17:36:23 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mr;

	if (size <= 0)
		return (NULL);
	if (!(mr = malloc(sizeof(size_t) * (int)size)))
		return (NULL);
	ft_memset(mr, 0, size);
	return (mr);
}
