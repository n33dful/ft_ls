/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:51:19 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/02 17:43:18 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_specx(char *num, t_printf *params)
{
	int	len;

	len = 0;
	if (num[0] == '0' && (num[1] == 'x' || num[1] == 'X'))
	{
		if (num[0] == '0' && num[1] == 'x')
			len += pf_putstr("0x", 2);
		else if (num[0] == '0' && num[1] == 'X')
			len += pf_putstr("0X", 2);
		len += pf_putcharntime('0', params->len - (int)ft_strlen(num));
		len += pf_putstr(num + 2, ft_strlen(num) - 2);
	}
	else
	{
		len += pf_putcharntime('0', params->len - (int)ft_strlen(num));
		len += pf_putstr(num, ft_strlen(num));
	}
	return (len);
}

static int	ft_putnx(char *num, t_printf *params)
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
			if (params->zero && params->acc == -1)
				len += ft_specx(num, params);
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

static char	*ft_set(char *sign, char *n, t_printf *params)
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
		{
			ft_strdel(&n);
			if (sign)
				ft_strdel(&sign);
			res = ft_strnew(0);
		}
		else
			res = pf_strjoindelboth(sign, n);
	}
	return (res);
}

static char	*ft_setcurrent(char *num, t_printf *params)
{
	char *res;
	char *sign;
	char *n;

	sign = ft_strnew(2);
	if (num[0] == '0' && (num[1] == 'x' || num[1] == 'X'))
	{
		sign = ft_strncpy(sign, num, 2);
		n = ft_strdup(num + 2);
	}
	else
		n = ft_strdup(num);
	res = ft_set(sign, n, params);
	return (res);
}

int			pf_convx(uintmax_t num, t_printf *params, char letter)
{
	int		len;
	char	*tmp;
	char	*new_num;

	len = 0;
	new_num = pf_itoa_base(num, 16);
	if (params->altform && num != 0)
	{
		tmp = ft_strjoin("0x", new_num);
		ft_strdel(&new_num);
		new_num = tmp;
	}
	if (letter == 'X')
	{
		tmp = ft_strmap(new_num, &pf_toupper);
		ft_strdel(&new_num);
		new_num = tmp;
	}
	if (params->acc >= 0)
		new_num = ft_setcurrent(new_num, params);
	len += ft_putnx(new_num, params);
	ft_strdel(&new_num);
	free(params);
	return (len);
}
