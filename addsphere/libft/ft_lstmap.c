/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:28:55 by ylisyak           #+#    #+#             */
/*   Updated: 2017/11/21 17:48:32 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nptr;
	t_list	*tmp;
	t_list	*strt;

	tmp = f(lst);
	if (!(nptr = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	strt = nptr;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(nptr->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		nptr = nptr->next;
		lst = lst->next;
	}
	return (strt);
}
