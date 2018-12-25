/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recognise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 01:22:56 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/23 03:17:07 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile(char *av)
{
	int		fd;
	int		i;
	char	str;
	char	*buf;

	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	while (read(fd, &str, 1) > 0)
		i++;
	if (!(buf = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	read(fd, buf, i);
	buf[i] = '\0';
	close(fd);
	return (buf);
}
