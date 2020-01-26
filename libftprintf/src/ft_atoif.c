/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoif.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:49:03 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/20 20:49:52 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_atoif(const char **str)
{
	unsigned long long	num;
	int					is_negative;

	num = 0;
	is_negative = 0;
	while (**str == ' ' || **str == '\n' || **str == '\f' ||\
	**str == '\t' || **str == '\v' || **str == '\r')
		str++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			is_negative = 1;
		str++;
	}
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		if (num > num * 10)
			return (is_negative ? 0 : -1);
		*str = *str + 1;
	}
	return (is_negative ? (-1 * (int)num) : (int)num);
}
