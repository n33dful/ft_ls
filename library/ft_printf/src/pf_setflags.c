/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:15:26 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:15:30 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isflag(char letter)
{
	if (letter == 'c' || letter == 's' || letter == 'p' || \
		letter == 'd' || letter == 'i' || letter == 'o' || \
		letter == 'u' || letter == 'x' || letter == 'X' || \
		letter == 'f' || letter == 'S' || letter == 'C' || \
		letter == 'Z')
		return (1);
	return (0);
}

static void	ft_setpar3(const char **format, t_printf *params, va_list ap)
{
	if (**format == '0')
	{
		*format += 1;
		params->zero = 1;
	}
	else if (**format >= '1' && **format <= '9')
		params->len = pf_atoi(format);
	else if (**format == '.')
	{
		*format += 1;
		params->acc = pf_atoi(format);
	}
	else if (**format == '*')
	{
		*format += 1;
		params->len = va_arg(ap, int);
	}
	else
		*format += 1;
}

static void	ft_setpar2(const char **format, t_printf *params, va_list ap)
{
	if (**format == 'h' && params->flagl == 0)
	{
		*format += 1;
		params->flagh = 1;
		if (**format == 'h')
		{
			*format += 1;
			params->flagh = 2;
		}
	}
	else if (**format == '-')
	{
		*format += 1;
		params->left = 1;
	}
	else if (**format == '+')
	{
		params->sign = 1;
		while (**format == '+')
			*format += 1;
	}
	else
		ft_setpar3(format, params, ap);
}

static void	ft_setpar1(const char **format, t_printf *params, va_list ap)
{
	if (**format == 'l' && params->flagh == 0)
	{
		*format += 1;
		params->flagl = 1;
		if (**format == 'l')
		{
			*format += 1;
			params->flagl = 2;
		}
	}
	else if (**format == 'L')
	{
		*format += 1;
		params->flagld = 1;
	}
	else
		ft_setpar2(format, params, ap);
}

t_printf	*pf_setflags(const char **format, va_list ap)
{
	t_printf	*params;

	params = pf_setbasicflags();
	*format += 1;
	while (!ft_isflag(**format) && **format != '\0')
	{
		if (**format == ' ')
		{
			params->space = 1;
			while (**format == ' ')
				*format += 1;
		}
		else if (**format == '%')
			break ;
		else if (**format == '#')
		{
			*format += 1;
			params->altform = 1;
		}
		else
			ft_setpar1(format, params, ap);
	}
	return (params);
}
