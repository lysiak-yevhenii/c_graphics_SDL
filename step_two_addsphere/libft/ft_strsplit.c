/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:10:44 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/26 18:12:07 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wdc(char *s, char c)
{
	int		word;
	int		i;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			word++;
		i++;
	}
	if (s[0] != '\0' && s[0] != c)
		word++;
	return (word);
}

static int		ft_strhack(char *str, char c, int i)
{
	int		n;

	n = 0;
	while (str[i] != c && str[i])
	{
		n++;
		i++;
	}
	return (n);
}

static char		*ft_wlen(char *str, char c, int *i)
{
	char	*s;
	int		j;

	if (!(s = (char *)malloc(sizeof(char) * (ft_strhack(str, c, *i) + 1))))
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i])
	{
		s[j] = str[*i];
		j++;
		*i += 1;
	}
	s[j] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(char const *s, int c)
{
	int		i;
	int		j;
	int		word;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	word = ft_wdc((char*)s, c);
	if (!(str = (char **)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < word && s[i])
	{
		str[j] = ft_wlen((char*)s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
