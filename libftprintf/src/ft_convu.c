/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:31:18 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/04 20:31:16 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_set(char *n, char *sign, t_params *params)
{
	char *res;

	if (params->acc > (int)ft_strlenf(n))
	{
		res = ft_strjoindelboth(ft_strbzero(params->acc - ft_strlenf(n)), n);
		if (sign[0] != '\0')
			res = ft_strjoindelboth(sign, res);
	}
	else
	{
		if (n[0] == '0')
			res = ft_strnewf(0);
		else
			res = n;
	}
	return (res);
}

static char	*ft_setcurrent(char *num, t_params *params)
{
	char *res;
	char *sign;
	char *n;

	sign = ft_strnewf(1);
	if (num[0] == '-' || num[0] == '+')
	{
		sign = ft_strncpyf(sign, num, 1);
		n = ft_strdupf(num + 1);
	}
	else
		n = ft_strdupf(num);
	res = ft_set(n, sign, params);
	ft_strdelf(&sign);
	ft_strdelf(&num);
	return (res);
}

int			ft_convu(uintmax_t n, t_params *params)
{
	int		count;
	char	*num;

	count = 0;
	num = ft_uitoa(n);
	if (params->acc >= 0)
		num = ft_setcurrent(num, params);
	count += ft_putn(num, params);
	ft_strdelf(&num);
	free(params);
	return (count);
}
