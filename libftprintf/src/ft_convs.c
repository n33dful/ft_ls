/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:26:53 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/30 19:47:23 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_settoleft(char *str, t_params *params)
{
	int	count;

	count = 0;
	if ((size_t)params->len > (ft_strlenf(str) < \
(size_t)params->acc ? ft_strlenf(str) : params->acc))
		if (params->acc == -1)
		{
			count += ft_putstrf(str, ft_strlenf(str));
			count += ft_putcharntime(' ', params->len - ft_strlenf(str));
		}
		else
		{
			count += ft_putstrf(str, params->acc);
			count += ft_putcharntime(' ', (params->len - \
((int)ft_strlenf(str) < params->acc ? ft_strlenf(str) : params->acc)));
		}
	else
	{
		if (params->acc == -1)
			count += ft_putstrf(str, ft_strlenf(str));
		else
			count += ft_putstrf(str, params->acc);
	}
	return (count);
}

static int	ft_settoright(char *str, t_params *params)
{
	int	count;

	count = 0;
	if ((size_t)params->len > (ft_strlenf(str) < \
(size_t)params->acc ? ft_strlenf(str) : params->acc))
		if (params->acc == -1)
		{
			count += ft_putcharntime(' ', params->len - ft_strlenf(str));
			count += ft_putstrf(str, ft_strlenf(str));
		}
		else
		{
			count += ft_putcharntime(' ', (params->len - \
((int)ft_strlenf(str) < params->acc ? ft_strlenf(str) : params->acc)));
			count += ft_putstrf(str, params->acc);
		}
	else
	{
		if (params->acc == -1)
			count += ft_putstrf(str, ft_strlenf(str));
		else
			count += ft_putstrf(str, params->acc);
	}
	return (count);
}

int			ft_convs(char *str, t_params *params)
{
	int	len;

	if (!str)
		str = ft_strdupf("(null)");
	else
		str = ft_strdupf(str);
	len = 0;
	if (params->left)
		len += ft_settoleft(str, params);
	else
		len += ft_settoright(str, params);
	ft_strdelf(&str);
	free(params);
	return (len);
}
