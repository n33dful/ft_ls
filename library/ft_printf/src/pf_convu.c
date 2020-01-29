/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:31:18 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/04 20:31:16 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_set(char *n, char *sign, t_printf *params)
{
	char *res;

	if (params->acc > (int)ft_strlen(n))
	{
		res = pf_strjoindelboth(pf_strbzero(params->acc - ft_strlen(n)), n);
		if (sign[0] != '\0')
			res = pf_strjoindelboth(sign, res);
	}
	else
	{
		if (n[0] == '0')
			res = ft_strnew(0);
		else
			res = n;
	}
	return (res);
}

static char	*ft_setcurrent(char *num, t_printf *params)
{
	char *res;
	char *sign;
	char *n;

	sign = ft_strnew(1);
	if (num[0] == '-' || num[0] == '+')
	{
		sign = ft_strncpy(sign, num, 1);
		n = ft_strdup(num + 1);
	}
	else
		n = ft_strdup(num);
	res = ft_set(n, sign, params);
	ft_strdel(&sign);
	ft_strdel(&num);
	return (res);
}

int			pf_convu(uintmax_t n, t_printf *params)
{
	int		count;
	char	*num;

	count = 0;
	num = pf_uitoa(n);
	if (params->acc >= 0)
		num = ft_setcurrent(num, params);
	count += pf_putn(num, params);
	ft_strdel(&num);
	free(params);
	return (count);
}
