/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:05:09 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/02 17:58:18 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_printf(const char *format, ...)
{
	int		count;
	va_list ap;

	count = 0;
	if (!format)
		exit(-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += pf_parse(&format, ap);
		else
			count += pf_putchar(*format);
		if (*format == '\0')
			break ;
		format++;
	}
	va_end(ap);
	return (count);
}
