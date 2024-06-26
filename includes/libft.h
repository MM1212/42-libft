/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:33:43 by mm                #+#    #+#             */
/*   Updated: 2024/04/09 11:31:18 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <printf/ft_printf.h>
# include <get_next_line.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef long long	t_ft_ll;
typedef long double	t_ft_ld;
typedef void		(*t_lst_iter)(void *content);
typedef void		(*t_lst_iter2)(void *content, void *data);
typedef int			(*t_lst_cmp)(void *a, void *b);
typedef int			(*t_lst_cmp2)(void *a, void *b, void *data);
typedef bool		(*t_lst_find)(void *content, void *data);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
bool	ft_isnbr(char *str, bool has_sign, bool floating);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_hexdump(void *ptr, size_t size, size_t dbpl);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
bool	ft_isupper(int c);
bool	ft_islower(int c);
char	*ft_struppercase(char *str);
char	*ft_strlowercase(char *str);
char	*ft_str_revcase(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnrchr(const char *s, int c, size_t n);
bool	ft_strchr_set(const char *str, const char *set);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
t_ft_ll	ft_atoll(const char *nptr);
t_ft_ld	ft_ceil(t_ft_ld n);
t_ft_ld	ft_floor(t_ft_ld n);
t_ft_ld	ft_round(t_ft_ld n, int precision);
t_ft_ld	ft_pow(t_ft_ld n, t_ft_ld pow);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(size_t count, ...);
char	*ft_strjoin2(char **strs);
// The last parameter must be NULL
char	*ft_strjoin_sep(char *sep, ...);
char	*ft_strjoin_sep2(char *sep, char **strs);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char *set);
void	ft_split_free(char **split);
char	*ft_itoa(int n);
char	*ft_ltoa(long nbr);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
bool	ft_str_startswith(const char *str, const char *substr);
bool	ft_str_endswith(const char *str, const char *substr);
char	*ft_strrep(char **str, size_t from, size_t len, char *rep);
int		ft_countchar(const char *str, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
long	ft_abs(long n);
int		ft_absi(int n);
double	ft_absf(double n);
size_t	ft_nbrlen_base(long nbr, uint32_t base);
size_t	ft_unbrlen_base(unsigned long nbr, uint32_t base);
size_t	ft_floatlen(double n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, t_lst_iter f);
void	ft_lstiter2(t_list *lst, t_lst_iter2 f, void *data);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstfind(t_list *lst, t_lst_find f, void *data);
void	ft_lstremove(t_list **list, t_list *node, void (*del)(void *));
t_list	*ft_lstsort(t_list *lst, t_lst_cmp cmp);
t_list	*ft_lstsort2(t_list *lst, t_lst_cmp2 cmp, void *data);
t_list	*ft_lstgoto_top(t_list **lst);
t_list	*ft_lstgoto_end(t_list **lst);
t_list	*ft_lstgoto(t_list **lst, int index);
void	ft_lstfclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_after(t_list **list, t_list *ref, t_list *node);
void	ft_lstadd_before(t_list **list, t_list *ref, t_list *node);
/* Wildcard Engine */
typedef struct s_wildcard_flags
{
	size_t	s_len;
	size_t	p_len;
	bool	case_insensitive;
}	t_wildcard_flags;
/* Bruteforce Method */
typedef struct s_wildcard
{
	const char			*str;
	const char			*pattern;
	size_t				s_len;
	size_t				p_len;
	size_t				s_idx;
	size_t				p_idx;
	int					last_wildcard_idx;
	int					backtrack_idx;
	int					next_to_wildcard_idx;
	t_wildcard_flags	flags;
}	t_wildcard;

bool	ft_wildcard_match(const char *pattern, const char *str);
bool	ft_wildcard_match2(\
	const char *pattern, const char *str, \
	t_wildcard_flags flags \
);

#endif
