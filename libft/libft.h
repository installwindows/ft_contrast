/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 23:08:11 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/03 21:54:42 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <wchar.h>
# include <stdarg.h>

int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);
int					gnl(const int fd, char **line);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
ssize_t				ft_putchar(char c);
ssize_t				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char const *s, int fd);
int					ft_putendl_fd(char const *s, int fd);
int					ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list				*ft_lstget(t_list *lst, const void *value,
					int (*cmp)(const void *, const void *));

char				*ft_strrev(char *s);
char				*ft_itoa_base(int n, int b);
int					ft_abs(int n);
int					ft_iswhitespace(char c);
int					ft_ctoi(char c);
double				ft_pow(double x, double y);
int					ft_atoi_base(char *s, int b);
char				**ft_squareplusplus(char ***src, int c, int old, int len);
char				*ft_stradd(char **dest, char *src);
char				*ft_strnadd(char **dest, int n);
void				*ft_memadd(void **dest, void *src, size_t dest_size,
					size_t src_size);
int					ft_putnbr_base(long long nbr, int base);
int					ft_itoc(int c);
ssize_t				ft_putnstr(const char *str, size_t n);
int					ft_numlen(int n);
int					ft_itocc(int i);
int					ft_putcnbr_base(long long nbr, int base);
int					ft_count_words(char const *s, char c);
int					ft_strichr(const char *s, int c);
int					ft_snumlen(long long n);
int					ft_unumlen_base(unsigned long long n, int base);
int					ft_putnchar(char c, unsigned int n);
int					ft_putdigit(long long nbr);
int					ft_putudigit_base(unsigned long long n, int base,
					int (*f)(int));
int					ft_wctomb(char *mb, wchar_t wc);
unsigned int		ft_revbits(unsigned int n);
char				**ft_sort_words(char **words, int nbwords);
void				ft_dump(const void *data, size_t size);
void				*ft_memdup(const void *source, size_t size);
int					ft_putdigit_fd(long long nbr, int fd);
int					ft_putudigit_base_fd(unsigned long long n, int base,
					int (*f)(int), int fd);
int					ft_putnchar_fd(char c, unsigned int n, int fd);
int					ft_putnstr_fd(const char *str, size_t n, int fd);

#endif
