/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 23:47:20 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/07 12:22:51 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BLANK(ws) (ws=='\t'||ws=='\v'||ws=='\n'||ws=='\f'||ws=='\r'||ws==' ')

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <stdio.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct		s_stack {
	int				*s;
	int				min;
	int				max;
	int				l;
	int				tot_l;
	int				*c;
	int				min_cost;
	int				count;
	int				print;
	int				print_color;
	int				operations;
}					t_stack;

typedef struct		s_list {
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl {
	int				r;
	int				newline;
	int				buffnl;
	int				buffsize;
	char			*buffsave;
}					t_gnl;

typedef struct		s_algo {
	char			*in;
	char			flag;
	char			flagh;
	int				flagm;
	int				width;
	int				precision;
	char			*length;
	int				spaces;
	char			spec;
	char			*arg_str;
	int				null_terminator;
	int				in_i;
	char			*out_str;
	va_list			ap;
}					t_algo;

void				visual_rr(t_stack a, t_stack b, int ab);
void				visual_rrr(t_stack a, t_stack b, int ab);
void				visual_r(t_stack s, t_stack d, int ab);
void				visual_p(t_stack dst, t_stack src, int ab);
void				visual_rx(t_stack a, t_stack b, int ab);
void				visual_p(t_stack dst, t_stack src, int ab);
void				move_stdout(int row);
void				ps_stacks(t_stack a, t_stack b, int start);
int					ft_count(char *str);
void				init_push(t_stack *a, t_stack *b);
void				ss(t_stack *a, t_stack *b, int ab);
void				s(t_stack *s, t_stack *d, int ab);
void				rr(t_stack *s, t_stack *d, int ab);
void				rrr(t_stack *a, t_stack *b, int ab);
void				r(t_stack *s, t_stack *d, int ab);
void				rx(t_stack *a, t_stack *b, int ab);
void				p(t_stack *dst, t_stack *src, int ab);
void				init(int ac, t_stack *a, t_stack *b);
void				init_av(char *av, t_stack *a, t_stack *b);
int					parse_av(char *av, t_stack *a);
int					parse_arr(int ac, char **av, t_stack *a);
int					verify(t_stack *x, int ab);
int					parse_args(char *line, t_stack *a, t_stack *b);
void				sort(t_stack *a, t_stack *b);
void				bubblesort(t_stack *a, t_stack *b);
void				ft_push_to_a(t_stack *s, t_stack *d);
void				ft_push_to_b(t_stack *s, t_stack *d);
void				rotatemin_b(t_stack *a, t_stack *b, int i);
void				rotatemin_a(t_stack *a, t_stack *b, int i);
void				btoa(t_stack *a, t_stack *b);
int					mindist(t_stack *b);
int					distance4(t_stack *x, int nbr);
int					calc_rot_atob(t_stack *x, int nbr);
int					calc_rot_btoa(t_stack *x, int nbr);
int					distance(t_stack *x, int nbr);
void				findcost_atob(t_stack *s, t_stack *d);
void				findcost_btoa(t_stack *s, t_stack *d);
void				findcost_atob_sub(t_stack *s, t_stack *d,
		int i, int rotate);
void				findcost_btoa_sub(t_stack *s, t_stack *d,
		int i, int rotate);
void				init_cost(t_stack *x);
int					distance5(t_stack *d, int nbr, int *rotate);
int					calc_rotval_atob(t_stack *d, int nbr, int *rotate);
int					calc_rotval_btoa(t_stack *d, int nbr, int *rotate);
void				minmax(t_stack *x);
int					ft_absvalue(int nbr);
int					ft_wordct(const char *str, char c);
int					parse_args(char *line, t_stack *a, t_stack *b);
int					get_next_line(const int fd, char **line);
char				*ft_padend(char *str, int size);
char				*ft_pad(char *str, int size);
void				revdebuff(t_algo *algo);
int					debuff(t_algo *algo);
void				arg_octal(t_algo *algo);
void				arg_hex(t_algo *algo);
void				arg_nbr(t_algo *algo);
void				adjuster(t_algo *algo);
void				arg_int(t_algo *algo, long long d);
void				asterisk(t_algo *algo, int type);
char				*prechrcat(char *s1, char *s2, int precision);
void				ft_strbeg(char *s1, char *s2);
void				arg_char(t_algo *algo);
void				arg_str(t_algo *algo);
void				find_spec(t_algo *algo);
void				find_length(t_algo *algo);
void				find_flag(t_algo *algo);
void				find_width(t_algo *algo);
void				run_spec(t_algo *algo);
void				run_width(t_algo *algo);
void				run_flag(t_algo *algo);
void				flipflag(t_algo *algo);
int					ft_findnchr(const char *s, int c, int start, int end);
char				*ft_strwcat(char *s1, const wchar_t wc);
int					ft_printf(const char *fmt, ...);
char				*ft_itoau(size_t n);
char				*ft_chrcat(char *s1, const char c);
int					ft_strwhite(char *str);
char				*ft_itoa_basel(unsigned long long value, long base);
char				*ft_itoa_base(int value, int base);
void				ft_delendchr(char *s1);
int					ft_findchr(const char *s, int c);
int					ft_strisalpha(char *str);
int					ft_strisdigit(char *str, int whitespace);
char				ft_lastchr(const char *str);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				ft_bzero(void *s, size_t n);
char				*ft_realloc(char *str, size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strrcat(char *s1, const char *s2, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *b, const char *l, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strlower(char *str);
char				*ft_strupper(char *str);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
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
char				*ft_itoal(long long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int c);
void				ft_putnbr(long int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

#endif
