/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 07:48:14 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/14 11:22:18 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_fmt
{
	int		len;
	int		offset;
	int		pad;
	int		width;
	int		precision;
	int		hashtag;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		dot;
	int		upper;
	va_list	args;
}	t_fmt;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
int		is_in_set(char c, const char *set);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_putchar_printf(t_fmt *fmt);
void	ft_putstr_printf(t_fmt *fmt);
void	ft_putptr_printf(t_fmt *fmt);
void	ft_putunbr_base_fd(unsigned long long n, int base, int fd);
void	ft_putint_printf(t_fmt *fmt);
void	ft_putfnbr_base_fd(long long n, int base, t_fmt *fmt, int fd);
void	ft_putuint_printf(char c, int base, t_fmt *fmt);
int		ft_unumlen(unsigned long long n, int base);
int		ft_numlen(int n, int base);
int		ft_abs(int i);
void	ft_putnstr_fd(char *s, int len, int fd);
int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *strread);
char	*ft_rest(char *strread);
char	*ft_get_line(char *strread);
char	*ft_strjoin_get_next_line(char *s1, char *s2);
char	*ft_join_get_next_line(char *dest, char *s1, char *s2);
long	ft_atol(const char *nptr);

#endif