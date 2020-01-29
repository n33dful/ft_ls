/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:26:53 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/30 19:47:23 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_settoleft(char *str, t_printf *params)
{
	int	count;

	count = 0;
	if ((size_t)params->len > (ft_strlen(str) < \
(size_t)params->acc ? ft_strlen(str) : params->acc))
		if (params->acc == -1)
		{
			count += pf_putstr(str, ft_strlen(str));
			count += pf_putcharntime(' ', params->len - ft_strlen(str));
		}
		else
		{
			count += pf_putstr(str, params->acc);
			count += pf_putcharntime(' ', (params->len - \
((int)ft_strlen(str) < params->acc ? ft_strlen(str) : params->acc)));
		}
	else
	{
		if (params->acc == -1)
			count += pf_putstr(str, ft_strlen(str));
		else
			count += pf_putstr(str, params->acc);
	}
	return (count);
}

static int	ft_settoright(char *str, t_printf *params)
{
	int	count;

	count = 0;
	if ((size_t)params->len > (ft_strlen(str) < \
(size_t)params->acc ? ft_strlen(str) : params->acc))
		if (params->acc == -1)
		{
			count += pf_putcharntime(' ', params->len - ft_strlen(str));
			count += pf_putstr(str, ft_strlen(str));
		}
		else
		{
			count += pf_putcharntime(' ', (params->len - \
((int)ft_strlen(str) < params->acc ? ft_strlen(str) : params->acc)));
			count += pf_putstr(str, params->acc);
		}
	else
	{
		if (params->acc == -1)
			count += pf_putstr(str, ft_strlen(str));
		else
			count += pf_putstr(str, params->acc);
	}
	return (count);
}

int			pf_convs(char *str, t_printf *params)
{
	int	len;

	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	len = 0;
	if (params->left)
		len += ft_settoleft(str, params);
	else
		len += ft_settoright(str, params);
	ft_strdel(&str);
	free(params);
	return (len);
}
