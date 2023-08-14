/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:32:09 by pcoletta          #+#    #+#             */
/*   Updated: 2022/06/21 11:54:35 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}					t_dlist;

t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_back(t_dlist **alst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **alst, t_dlist *new);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstfirst(t_dlist *lst);
void	ft_dlstclear(t_dlist **lst, void (*del)(void *));
void	ft_dlstdelone(t_dlist *lst, void (*del)(void *));
void	ft_dlstpop_front(t_dlist **head, void (*del)(void*));
void	ft_dlstpop_back(t_dlist **head, void (*del)(void*));
void	ft_dlstclearback_addr(t_dlist **lst, void (*del)(void **));
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *s1, const char *s2, size_t dstsize);
char	*ft_strchr(const char *s, int c);
int		ft_strichr(const char *str, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_stristr(const char *str, char *stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strappend(char **str, char c);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isonly(char *str, char c);
int		ft_isonly_ft(char *str, int (*ftissmth)(int c), int strict);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char const *s1, char const *s2, int to_free);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strstradd(char **dst, int start, char *src);
void	ft_strcdel(char *str, size_t i);
char	**ft_split(char const *s, char c);
char	**ft_split_whitespaces(char const *s, char *ifs);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_array_len(char **array);
void	*ft_array_free(char **ptr, int k);
t_list	*ft_lstnew(void const *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)(), \
	void (*free_fct)(void *));
void	ft_free(void **ptr);
void	*ft_memalloc(size_t size);

#endif
