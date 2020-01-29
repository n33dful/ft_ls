/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:25:27 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/30 19:47:23 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_settoleft(char *str, t_printf *params)
{
	int	len;

	len = 0;
	if ((size_t)params->len > ft_strlen(str))
	{
		len += pf_putstr(str, ft_strlen(str));
		len += pf_putcharntime(' ', (long long)(params->len - ft_strlen(str)));
	}
	else
		len += pf_putstr(str, ft_strlen(str));
	return (len);
}

static int	ft_settoright(char *str, t_printf *params)
{
	int	len;

	len = 0;
	if ((size_t)params->len > ft_strlen(str))
	{
		len += pf_putcharntime(' ', (long long)(params->len - ft_strlen(str)));
		len += pf_putstr(str, ft_strlen(str));
	}
	else
		len += pf_putstr(str, ft_strlen(str));
	return (len);
}

static char	*ft_setcurrent(char *adr, t_printf *params)
{
	char	*zer;
	char	*res;
	size_t	i;

	i = 0;
	if (params->acc > (int)ft_strlen(adr))
	{
		zer = ft_strnew(params->acc - ft_strlen(adr));
		while (i < params->acc - ft_strlen(adr))
		{
			zer[i] = '0';
			i++;
		}
		zer[i] = '\0';
		res = pf_strjoindelboth(zer, adr);
		res = pf_strjoindelsecond("0x", res);
	}
	else
		res = pf_strjoindelsecond("0x", adr);
	return (res);
}

int			pf_convp(void *var, t_printf *params)
{
	int		len;
	char	*tmp;
	char	*adr;

	adr = pf_itoa_base((size_t)var, 16);
	if (params->acc == 0 && (size_t)var < 1000000000000000)
		tmp = ft_strdup("0x");
	else if (params->acc >= 0 && (size_t)var < 1000000000000000)
		tmp = ft_setcurrent(adr, params);
	else
		tmp = pf_strjoindelsecond("0x", adr);
	adr = tmp;
	len = 0;
	if (params->left)
		len += ft_settoleft(adr, params);
	else
		len += ft_settoright(adr, params);
	ft_strdel(&adr);
	free(params);
	return (len);
}
