/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:59:46 by ylisyak           #+#    #+#             */
/*   Updated: 2018/08/17 17:46:13 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*gnl_append(t_gnl *gnl)
{
	int				i;

	i = 0;
	gnl->nl = 0;
	while (gnl->i + i < gnl->count)
	{
		if (gnl->buf[gnl->i + i] == '\n')
		{
			gnl->nl = 1;
			i++;
			break ;
		}
		i++;
	}
	gnl->i += i;
	return (ft_strsub(gnl->buf, gnl->i - i, i - gnl->nl));
}

static void			gnl_free(t_list **lst, int fd, char **str)
{
	t_gnl			*gnl;
	t_list			**tmp;
	t_list			*ptr;

	tmp = lst;
	while (*tmp)
	{
		gnl = (t_gnl *)((*tmp)->content);
		if (gnl->fd == fd)
			break ;
		*tmp = ((*tmp)->next);
	}
	if (*tmp)
	{
		ptr = (*tmp)->next;
		ft_strdel(&(gnl->buf));
		ft_memdel((void **)&gnl);
		ft_memdel((void **)tmp);
		*tmp = ptr;
	}
	ft_strdel(str);
}

static int			read_buff(t_gnl *gnl, t_list **lst, char **tmp, char **line)
{
	if (gnl->i == gnl->count)
	{
		gnl->count = read(gnl->fd, gnl->buf, BUFF_SIZE);
		if (gnl->count == -1)
		{
			gnl_free(lst, gnl->fd, tmp);
			return (-1);
		}
		gnl->i = 0;
		if (gnl->count == 0)
		{
			if (gnl->nl == 0)
			{
				*line = *tmp;
				return (1);
			}
		}
	}
	return (0);
}

static t_gnl		*get_by_fd(t_list **lst, int fd)
{
	t_list			*tmp;
	t_gnl			*gnl;

	tmp = *lst;
	while (tmp)
	{
		gnl = (t_gnl *)(tmp->content);
		if (gnl->fd == fd)
			return (gnl);
		tmp = tmp->next;
	}
	gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	gnl->buf = ft_strnew(BUFF_SIZE);
	gnl->i = BUFF_SIZE;
	gnl->fd = fd;
	gnl->nl = 1;
	gnl->count = BUFF_SIZE;
	tmp = ft_lstnew(gnl, sizeof(t_gnl));
	ft_memdel((void **)&gnl);
	ft_lstadd(lst, tmp);
	return ((t_gnl *)(tmp->content));
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_gnl			*current;
	char			*tmp;
	int				bit;

	if (fd < 0 || line == NULL)
		return (-1);
	current = get_by_fd(&lst, fd);
	tmp = ft_strnew(0);
	while (current->count > 0)
	{
		if ((bit = read_buff(current, &lst, &tmp, line)) != 0)
			return (bit);
		while (current->i < current->count)
		{
			tmp = ft_strmerge(tmp, gnl_append(current));
			if (current->nl)
			{
				*line = tmp;
				return (1);
			}
		}
	}
	gnl_free(&lst, fd, &tmp);
	return (0);
}
