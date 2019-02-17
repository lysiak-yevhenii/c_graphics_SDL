/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:08:41 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/21 16:55:34 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nextlst;
	t_list *ptr;

	ptr = *alst;
	while (ptr)
	{
		nextlst = ptr->next;
		(*del)(ptr->content, ptr->content_size);
		free(ptr);
		ptr = nextlst;
	}
	*alst = NULL;
}
