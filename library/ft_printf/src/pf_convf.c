/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:21:38 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/04 20:30:43 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putnf(char *num, t_printf *params)
{
	int	len;

	len = 0;
	if (params->left)
		if (params->len > ft_strlen(num))
		{
			len += pf_putstr(num, ft_strlen(num));
			len += pf_putcharntime(' ', params->len - (int)ft_strlen(num));
		}
		else
			len += pf_putstr(num, ft_strlen(num));
	else
	{
		if (params->len > ft_strlen(num))
			if (params->zero)
				len += pf_spec(num, params);
			else
			{
				len += pf_putcharntime(' ', params->len - (int)ft_strlen(num));
				len += pf_putstr(num, ft_strlen(num));
			}
		else
			len += pf_putstr(num, ft_strlen(num));
	}
	return (len);
}

static char	*new_hvost(long double num, t_printf *params)
{
	char		*str_num;
	int			accur;
	int			i;

	i = 0;
	accur = params->acc;
	str_num = ft_strnew(0);
	if (accur >= 0)
	{
		if (accur == 0)
		{
			ft_strdel(&str_num);
			return (NULL);
		}
	}
	else
		accur = 6;
	while (i < accur)
	{
		num *= 10;
		str_num = pf_strjoindelboth(str_num, pf_uitoa((uintmax_t)num % 10));
		num -= ((uintmax_t)num);
		i++;
	}
	return (str_num);
}

static char	*ft_findint(long double num, t_printf *params)
{
	char *n;

	n = NULL;
	if (num < 0)
		n = pf_strjoindelsecond("-", pf_uitoa((uintmax_t)(num *= -1)));
	else
		n = pf_uitoa((uintmax_t)(num));
	if (params->sign)
	{
		if (n[0] != '-')
			n = pf_strjoindelsecond("+", n);
	}
	else if (params->space)
	{
		if (n[0] != '-')
			n = pf_strjoindelsecond(" ", n);
	}
	return (n);
}

static void	ft_rounding(long double *num, t_printf *params)
{
	long double	param;
	int			acc;
	int			i;

	i = 0;
	param = 0.5;
	acc = params->acc;
	if (acc < 0)
		acc = 6;
	while (i < acc)
	{
		param *= 0.1;
		i++;
	}
	if ((*num) < 0)
		(*num) += -1 * param;
	else
		(*num) += param;
}

int			pf_convf(long double num, t_printf *params)
{
	char		*res;
	char		*s_in;
	char		*s_par;
	int			len;

	len = 0;
	ft_rounding(&num, params);
	s_in = ft_findint(num, params);
	s_par = new_hvost((num < 0 ? -1 * (num + \
(uintmax_t)(-1 * num)) : num - (uintmax_t)num), params);
	if (params->altform || s_par != NULL)
	{
		res = pf_strjoindelfirst(s_in, ".");
		if (s_par != NULL)
			res = pf_strjoindelboth(res, s_par);
	}
	else
		res = s_in;
	len += ft_putnf(res, params);
	ft_strdel(&res);
	free(params);
	return (len);
}
