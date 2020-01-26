/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convdi.c                                        :+:      :+:    :+:   */
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
		ft_strdelf(res);
		if (sign[0] == '+')
			(*res) = ft_strdupf("+");
		else
			(*res) = ft_strnewf(0);
	}
	else if (sign[0] != '\0')
		(*res) = ft_strjoindelboth(sign, n);
	else
	{
		(*res) = ft_strdupf(num);
		ft_strdelf(&sign);
	}
}

static void	ft_break(char *num, char **sign, char **n)
{
	if (num[0] == ' ')
	{
		if (num[1] == '-' || num[1] == '+')
		{
			(*sign) = ft_strncpyf((*sign), num, 2);
			(*n) = ft_strdupf(num + 2);
		}
		else
		{
			(*sign) = ft_strncpyf((*sign), num, 1);
			(*n) = ft_strdupf(num + 1);
		}
	}
	else if (num[0] == '-' || num[0] == '+')
	{
		(*sign) = ft_strncpyf((*sign), num, 1);
		(*n) = ft_strdupf(num + 1);
	}
	else
		(*n) = ft_strdupf(num);
}

static char	*ft_setcurrent(char *num, t_params *params)
{
	char *res;
	char *sign;
	char *n;

	res = NULL;
	n = NULL;
	sign = ft_strnewf(2);
	ft_break(num, &sign, &n);
	if (params->acc > (int)ft_strlenf(n))
	{
		res = ft_strjoindelboth(ft_strbzero(params->acc - ft_strlenf(n)), n);
		if (sign[0] != '\0')
			res = ft_strjoindelboth(sign, res);
		else
			ft_strdelf(&sign);
	}
	else
		ft_set(&res, n, sign, num);
	ft_strdelf(&num);
	return (res);
}

int			ft_convdi(intmax_t n, t_params *params)
{
	int		count;
	char	*num;

	count = 0;
	num = ft_itoaf(n);
	if (params->sign)
	{
		if (num[0] != '-')
			num = ft_strjoindelsecond("+", num);
	}
	else if (params->space)
	{
		if (num[0] != '-')
			num = ft_strjoindelsecond(" ", num);
	}
	if (params->acc >= 0)
		num = ft_setcurrent(num, params);
	count += ft_putn(num, params);
	ft_strdelf(&num);
	free(params);
	return (count);
}
