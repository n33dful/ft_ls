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

/*
** ----------------------------- External Headers ------------------------------
*/

# include "../../get_next_line/incl/get_next_line.h"
# include <stdarg.h>
# include <limits.h>

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct		s_pintf
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
}					t_printf;

/*
** -----------------------------------------------------------------------------
** ---------------------------------- Sources ----------------------------------
** -----------------------------------------------------------------------------
*/

int					ft_printf(const char *format, ...);

size_t				pf_putcharntime(const char c, size_t time);
size_t				pf_putstr(char const *s, size_t len);
void				ft_putadr(void *var);

char				*pf_uitoa(uintmax_t n);
char				*pf_itoa_base(uintmax_t num, uintmax_t base);
char				*pf_strbzero(size_t len);
char				*pf_strjoindelboth(char *s1, char *s2);
char				*pf_strjoindelfirst(char *s1, char const *s2);
char				*pf_strjoindelsecond(char const *s1, char *s2);
char				*pf_itoa(intmax_t n);
char				pf_toupper(char c);

int					pf_atoi(const char **str);
int					pf_putchar(char c);
int					pf_spec(char *num, t_printf *params);
int					pf_putn(char *num, t_printf *params);
int					pf_parse(const char **format, va_list ap);
int					pf_convc(int letter, t_printf *params);
int					pf_convs(char *str, t_printf *params);
int					pf_convp(void *var, t_printf *params);
int					pf_convdi(intmax_t n, t_printf *params);
int					pf_convo(uintmax_t num, t_printf *params);
int					pf_convu(uintmax_t n, t_printf *params);
int					pf_convx(uintmax_t num, t_printf *params, char letter);
int					pf_convf(long double num, t_printf *params);

t_printf			*pf_setbasicflags(void);
t_printf			*pf_setflags(const char **format, va_list ap);

#endif
