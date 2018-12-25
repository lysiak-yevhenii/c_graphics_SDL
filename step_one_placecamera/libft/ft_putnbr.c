/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 06:57:03 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/21 18:58:15 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	news;
	unsigned int	pronew;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	pronew = (unsigned int)n;
	news = pronew % 10;
	pronew = pronew / 10;
	if (pronew != 0)
		ft_putnbr(pronew);
	ft_putchar((char)news + '0');
}
