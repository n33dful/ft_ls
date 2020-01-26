/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:08:12 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/02 17:58:09 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct		s_paramlist
{
	int				acc;
	int				left;
	size_t			len;
	int				altform;
	char			space;
	char			sign;
	char			zero;
	char			flagl;
	char			flagh;
	char			flagld;
}					t_params;

size_t				ft_strlenf(const char *s);
size_t				ft_putcharntime(const char c, size_t time);
size_t				ft_putstrf(char const *s, size_t len);

void				ft_strrew(char *str);
void				ft_putadr(void *var);
void				ft_strdelf(char **as);
void				*ft_memallocf(size_t size);

char				ft_toupperf(char c);
char				*ft_uitoa(uintmax_t n);
char				*ft_itoa_base(uintmax_t num, uintmax_t base);
char				*ft_strbzero(size_t len);
char				*ft_strmapf(char const *s, char (*f)(char));
char				*ft_strdupf(const char *s1);
char				*ft_strcpyf(char *dst, const char *src);
char				*ft_strncpyf(char *dst, const char *src, size_t len);
char				*ft_strnewf(size_t size);
char				*ft_strsubf(char const *s, unsigned int start, size_t len);
char				*ft_strjoinf(char const *s1, char const *s2);
char				*ft_strjoindelboth(char *s1, char *s2);
char				*ft_strjoindelfirst(char *s1, char const *s2);
char				*ft_strjoindelsecond(char const *s1, char *s2);
char				*ft_itoaf(intmax_t n);

int					ft_atoif(const char **str);
int					ft_putnbrf(int n);
int					ft_putcharf(char c);
int					ft_spec(char *num, t_params *params);
int					ft_putn(char *num, t_params *params);
int					ft_parse(const char **format, va_list ap);
int					ft_convc(int letter, t_params *params);
int					ft_convs(char *str, t_params *params);
int					ft_convp(void *var, t_params *params);
int					ft_convdi(intmax_t n, t_params *params);
int					ft_convo(uintmax_t num, t_params *params);
int					ft_convu(uintmax_t n, t_params *params);
int					ft_convx(uintmax_t num, t_params *params, char letter);
int					ft_convf(long double num, t_params *params);
int					ft_printf(const char *format, ...);

t_params			*ft_setbasicflags(void);
t_params			*ft_setflagsprnf(const char **format, va_list ap);

#endif
