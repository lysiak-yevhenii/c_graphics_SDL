/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:36:40 by ylisyak           #+#    #+#             */
/*   Updated: 2018/08/17 18:37:15 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strdup(s1);
	if (s1)
		free(s1);
	s1 = ft_strjoin(tmp, s2);
	free(tmp);
	return (s1);
}
