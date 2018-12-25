/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:54:53 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/25 20:35:02 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_filchek(int ck, int sh)
{
	int		rm;

	rm = 0;
	if ((ck == 3 || ck == 4) && sh == 4)
		rm++;
	return (rm);
}

static void		ft_filvalr(int *i, int *ck, int *sh, int *rm)
{
	*i = 0;
	*ck = 0;
	*sh = 0;
	*rm = 0;
}

static int		ft_compres(char *s, int rm)
{
	if (ft_filct(s) == rm)
		return (1);
	else
		return (0);
}

static void		ft_renew(int *i, int *sh, int *ck)
{
	*sh = 0;
	*i = *i + 2;
	*ck = 0;
}

int				ft_filval(char *s)
{
	int		i;
	int		ck;
	int		sh;
	int		rm;

	ft_filvalr(&i, &ck, &sh, &rm);
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
		{
			rm = rm + ft_filchek(ck, sh);
			if (s[i + 1] != '\0')
				ft_renew(&i, &sh, &ck);
		}
		if (s[i] == '#')
		{
			if (s[i + 1] == '#')
				ck++;
			if (s[i + 5] == '#')
				ck++;
			sh++;
		}
		i++;
	}
	return (ft_compres(s, rm));
}
