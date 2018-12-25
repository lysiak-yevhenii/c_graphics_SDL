/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:28:20 by ylisyak           #+#    #+#             */
/*   Updated: 2018/11/13 04:15:08 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 4096

typedef struct		s_gnl
{
	int				i;
	int				fd;
	int				nl;
	int				count;

	char			*buf;
}					t_gnl;

int					ft_atoi(const char *nb);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_nbrlen(int tmpd);
int					ft_strlen_from(char *s, int from);
int					ft_strlen_until(char *s, int until);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t bits);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_itoa(int a);
char				*ft_strmerge(char *a, char *b);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *s, const char *needly);
char				*ft_strnstr(const char *dest, const char *src, size_t bits);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *dest, char *src, size_t n);
char				*ft_strcat(char *dest, char const *src);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strncat(char *dest, const char *src, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_strsplit(char const *s, int c);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr(const char *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char*));
void				ft_strdel(char **as);
void				ft_memdel(void	**ap);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memset(void *dest, int c, size_t nofb);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *a);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list	**alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

char				*ft_arena(int size);
int					ft_fillitsq(int tcount);
char				*ft_readfile(char *av);
int					ft_filval(char *s);
int					ft_filct(char *s);
int					ft_atoi_base(char *str, int base);

int					ft_radian_in_degree(double radian);
float				ft_degree_in_radian(int degree);

int					get_next_line(int const fd, char **line);
#endif
