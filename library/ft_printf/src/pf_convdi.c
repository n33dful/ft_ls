/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convdi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:29:25 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/02 16:53:29 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_set(char **res, char *n, char *sign, char *num)
{
	if (n[0] == '0')
	{
		ft_strdel(res);
		if (sign[0] == '+')
			(*res) = ft_strdup("+");
		else
			(*res) = ft_strnew(0);
	}
	else if (sign[0] != '\0')
		(*res) = pf_strjoindelboth(sign, n);
	else
	{
		(*res) = ft_strdup(num);
		ft_strdel(&sign);
	}
}

static void	ft_break(char *num, char **sign, char **n)
{
	if (num[0] == ' ')
	{
		if (num[1] == '-' || num[1] == '+')
		{
			(*sign) = ft_strncpy((*sign), num, 2);
			(*n) = ft_strdup(num + 2);
		}
		else
		{
			(*sign) = ft_strncpy((*sign), num, 1);
			(*n) = ft_strdup(num + 1);
		}
	}
	else if (num[0] == '-' || num[0] == '+')
	{
		(*sign) = ft_strncpy((*sign), num, 1);
		(*n) = ft_strdup(num + 1);
	}
	else
		(*n) = ft_strdup(num);
}

static char	*ft_setcurrent(char *num, t_printf *params)
{
	char *res;
	char *sign;
	char *n;

	res = NULL;
	n = NULL;
	sign = ft_strnew(2);
	ft_break(num, &sign, &n);
	if (params->acc > (int)ft_strlen(n))
	{
		res = pf_strjoindelboth(pf_strbzero(params->acc - ft_strlen(n)), n);
		if (sign[0] != '\0')
			res = pf_strjoindelboth(sign, res);
		else
			ft_strdel(&sign);
	}
	else
		ft_set(&res, n, sign, num);
	ft_strdel(&num);
	return (res);
}

int			pf_convdi(intmax_t n, t_printf *params)
{
	int		count;
	char	*num;

	count = 0;
	num = pf_itoa(n);
	if (params->sign)
	{
		if (num[0] != '-')
			num = pf_strjoindelsecond("+", num);
	}
	else if (params->space)
	{
		if (num[0] != '-')
			num = pf_strjoindelsecond(" ", num);
	}
	if (params->acc >= 0)
		num = ft_setcurrent(num, params);
	count += pf_putn(num, params);
	ft_strdel(&num);
	free(params);
	return (count);
}
