/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:50:16 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/07 11:50:16 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 32

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_params
{
	int		point;
	int		hyphen;
	int		zero;
	int		width;
	int		hpoint;
	int		hhyphen;
	int		hzero;
	int		hwidth;
	int		invalid;
}					t_params;

int					ft_printf(const char *format, ...);
t_params			read_params(const char *f, char c, va_list a);
int					is_legal_char(char c, char d);
void				init_param(t_params *t);
void				update_params(t_params *t, char c);
void				read_zero(const char *f, t_params *t, int *k, va_list a);
void				read_hyphen(const char *f, t_params *t, int *k, va_list a);
void				read_point(const char *f, t_params *t, int *k, va_list a);
void				read_width(const char *f, t_params *t, int *k, va_list a);
void				read_width_0(const char *f, t_params *t, int *k);
int					parse_flags(const char *f, va_list a, int *c);
int					parse_d(const char *format, va_list a);
int					parse_zero(const char *format, va_list a);
int					parse_p(const char *format, va_list a);
int					parse_i(const char *format, va_list a);
int					parse_c(const char *format, va_list a);
int					parse_pc(const char *format, va_list a);
int					parse_s(const char *format, va_list a);
int					parse_u(const char *format, va_list a);
int					parse_x(const char *format, va_list a);
int					parse_xm(const char *format, va_list a);
char				*join_char_and_free(char *str, char c);
char				*char_join_and_free(char *str, char c);
char				*ft_strjoin_and_free(char *t1, char *t2);
long int			vo_atoi(const char *str, int *count);
char				*u_int_to_hexa(unsigned int i, char alpha, int mode);
char				*long_int_to_hexa(long int i, char alpha, int mode);
void				free_many(char *s1, char *s2);
unsigned int		ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(long int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup_to_c(const char *s1, char c);
char				*vo_strdup_2(const char *s1);
char				*vo_itoa(long int n);
void				free_many(char *s1, char *s2);
char				*vo_strdup(const char *s1);
int					get_next_line(int fd, char **line);
int					ft_len(const char *str);
int					ft_inset_s(char *c, char *set);
int					ft_inset_c(char c, char *set);
int					sign(float a);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
float				ft_dist(float a, float b);

#endif
