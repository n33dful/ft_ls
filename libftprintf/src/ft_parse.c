/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:57:22 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/07 20:29:53 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_part4(const char **format, va_list ap, t_params *params)
{
	if (**format == 'X' && params->flagl == 0 && params->flagh == 1)
		return (ft_convx((unsigned short)va_arg(ap, unsigned int), \
params, 'X'));
	else if (**format == 'X' && params->flagl == 0 && params->flagh == 2)
		return (ft_convx((unsigned char)va_arg(ap, unsigned int), \
params, 'X'));
	else if (**format == 'f' && (params->flagl == 0 || params->flagl == 1) && \
params->flagld == 0)
		return (ft_convf(va_arg(ap, double), params));
	else if (**format == 'f' && params->flagl == 0 && params->flagld == 1)
		return (ft_convf(va_arg(ap, long double), params));
	else if (**format == '%')
		return (ft_convc('%', params));
	else if (**format == 'Z')
		return (ft_putcharf('Z'));
	return (-1);
}

static int	ft_part3(const char **format, va_list ap, t_params *params)
{
	if (**format == 'x' && params->flagl == 1 && params->flagh == 0)
		return (ft_convx(va_arg(ap, unsigned long), params, 'x'));
	else if (**format == 'x' && params->flagl == 2 && params->flagh == 0)
		return (ft_convx(va_arg(ap, unsigned long long), params, 'x'));
	else if (**format == 'x' && params->flagl == 0 && params->flagh == 1)
		return (ft_convx((unsigned short)va_arg(ap, unsigned int), \
params, 'x'));
	else if (**format == 'x' && params->flagl == 0 && params->flagh == 2)
		return (ft_convx((unsigned char)va_arg(ap, unsigned int), params, 'x'));
	else if (**format == 'X' && params->flagl == 0 && params->flagh == 0)
		return (ft_convx(va_arg(ap, unsigned int), params, 'X'));
	else if (**format == 'X' && params->flagl == 1 && params->flagh == 0)
		return (ft_convx(va_arg(ap, unsigned long), params, 'X'));
	else if (**format == 'X' && params->flagl == 2 && params->flagh == 0)
		return (ft_convx(va_arg(ap, unsigned long long), params, 'X'));
	return (-1);
}

static int	ft_part2(const char **format, va_list ap, t_params *params)
{
	if (**format == 'i' && params->flagl == 0 && params->flagh == 2)
		return (ft_convdi((signed char)va_arg(ap, int), params));
	else if (**format == 'o' && params->flagl == 0 && params->flagh == 0)
		return (ft_convo(va_arg(ap, unsigned int), params));
	else if (**format == 'o' && params->flagl == 1 && params->flagh == 0)
		return (ft_convo(va_arg(ap, unsigned long), params));
	else if (**format == 'o' && params->flagl == 2 && params->flagh == 0)
		return (ft_convo(va_arg(ap, unsigned long long), params));
	else if (**format == 'o' && params->flagl == 0 && params->flagh == 1)
		return (ft_convo((unsigned short)va_arg(ap, int), params));
	else if (**format == 'o' && params->flagl == 0 && params->flagh == 2)
		return (ft_convo((unsigned char)va_arg(ap, int), params));
	else if (**format == 'u' && params->flagl == 0 && params->flagh == 0)
		return (ft_convu(va_arg(ap, unsigned int), params));
	else if (**format == 'u' && params->flagl == 1 && params->flagh == 0)
		return (ft_convu((uintmax_t)((size_t)va_arg(ap, long)), params));
	else if (**format == 'u' && params->flagl == 2 && params->flagh == 0)
		return (ft_convu(va_arg(ap, unsigned long long), params));
	else if (**format == 'u' && params->flagl == 0 && params->flagh == 1)
		return (ft_convu((unsigned short)va_arg(ap, int), params));
	else if (**format == 'u' && params->flagl == 0 && params->flagh == 2)
		return (ft_convu(((unsigned char)va_arg(ap, int)), params));
	else if (**format == 'x' && params->flagl == 0 && params->flagh == 0)
		return (ft_convx(va_arg(ap, unsigned int), params, 'x'));
	return (-1);
}

static int	ft_part1(const char **format, va_list ap, t_params *params)
{
	if (**format == 'c')
		return (ft_convc(va_arg(ap, int), params));
	else if (**format == 's')
		return (ft_convs(va_arg(ap, char *), params));
	else if (**format == 'p')
		return (ft_convp(va_arg(ap, void *), params));
	else if (**format == 'd' && params->flagl == 0 && params->flagh == 0)
		return (ft_convdi(va_arg(ap, int), params));
	else if (**format == 'd' && params->flagl == 1 && params->flagh == 0)
		return (ft_convdi(va_arg(ap, long), params));
	else if (**format == 'd' && params->flagl == 2 && params->flagh == 0)
		return (ft_convdi(va_arg(ap, long long), params));
	else if (**format == 'd' && params->flagl == 0 && params->flagh == 1)
		return (ft_convdi((short)va_arg(ap, int), params));
	else if (**format == 'd' && params->flagl == 0 && params->flagh == 2)
		return (ft_convdi((signed char)va_arg(ap, int), params));
	else if (**format == 'i' && params->flagl == 0 && params->flagh == 0)
		return (ft_convdi(va_arg(ap, int), params));
	else if (**format == 'i' && params->flagl == 1 && params->flagh == 0)
		return (ft_convdi(va_arg(ap, long), params));
	else if (**format == 'i' && params->flagl == 2 && params->flagh == 0)
		return (ft_convdi(va_arg(ap, long long), params));
	else if (**format == 'i' && params->flagl == 0 && params->flagh == 1)
		return (ft_convdi((short)va_arg(ap, int), params));
	return (-1);
}

int			ft_parse(const char **format, va_list ap)
{
	t_params	*params;
	int			res;

	params = ft_setflagsprnf(format, ap);
	if ((res = ft_part1(format, ap, params)) > -1)
		return (res);
	else if ((res = ft_part2(format, ap, params)) > -1)
		return (res);
	else if ((res = ft_part3(format, ap, params)) > -1)
		return (res);
	else if ((res = ft_part4(format, ap, params)) > -1)
		return (res);
	free(params);
	return (0);
}
