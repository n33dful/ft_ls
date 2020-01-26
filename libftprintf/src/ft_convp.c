/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:25:27 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/30 19:47:23 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_settoleft(char *str, t_params *params)
{
	int	len;

	len = 0;
	if ((size_t)params->len > ft_strlenf(str))
	{
		len += ft_putstrf(str, ft_strlenf(str));
		len += ft_putcharntime(' ', (long long)(params->len - ft_strlenf(str)));
	}
	else
		len += ft_putstrf(str, ft_strlenf(str));
	return (len);
}

static int	ft_settoright(char *str, t_params *params)
{
	int	len;

	len = 0;
	if ((size_t)params->len > ft_strlenf(str))
	{
		len += ft_putcharntime(' ', (long long)(params->len - ft_strlenf(str)));
		len += ft_putstrf(str, ft_strlenf(str));
	}
	else
		len += ft_putstrf(str, ft_strlenf(str));
	return (len);
}

static char	*ft_setcurrent(char *adr, t_params *params)
{
	char	*zer;
	char	*res;
	size_t	i;

	i = 0;
	if (params->acc > (int)ft_strlenf(adr))
	{
		zer = ft_strnewf(params->acc - ft_strlenf(adr));
		while (i < params->acc - ft_strlenf(adr))
		{
			zer[i] = '0';
			i++;
		}
		zer[i] = '\0';
		res = ft_strjoindelboth(zer, adr);
		res = ft_strjoindelsecond("0x", res);
	}
	else
		res = ft_strjoindelsecond("0x", adr);
	return (res);
}

int			ft_convp(void *var, t_params *params)
{
	int		len;
	char	*tmp;
	char	*adr;

	adr = ft_itoa_base((size_t)var, 16);
	if (params->acc == 0 && (size_t)var < 1000000000000000)
		tmp = ft_strdupf("0x");
	else if (params->acc >= 0 && (size_t)var < 1000000000000000)
		tmp = ft_setcurrent(adr, params);
	else
		tmp = ft_strjoindelsecond("0x", adr);
	adr = tmp;
	len = 0;
	if (params->left)
		len += ft_settoleft(adr, params);
	else
		len += ft_settoright(adr, params);
	ft_strdelf(&adr);
	free(params);
	return (len);
}
