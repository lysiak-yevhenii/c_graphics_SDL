/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:08:04 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/21 18:58:41 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	news;
	unsigned int	pronew;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	pronew = (unsigned int)n;
	news = pronew % 10;
	pronew = pronew / 10;
	if (pronew != 0)
		ft_putnbr_fd(pronew, fd);
	ft_putchar_fd((char)news + '0', fd);
}
