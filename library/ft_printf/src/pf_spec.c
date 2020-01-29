/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:46:13 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/02 16:46:43 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_spec(char *num, t_printf *params)
{
	int	len;

	len = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		if (num[0] == '-')
			len += pf_putchar('-');
		else if (num[0] == '+')
			len += pf_putchar('+');
		len += pf_putcharntime('0', params->len - (int)ft_strlen(num));
		len += pf_putstr(num + 1, ft_strlen(num) - 1);
	}
	else
	{
		if (num[0] == ' ')
			len += pf_putchar(' ');
		len += pf_putcharntime('0', params->len - (int)ft_strlen(num));
		if (num[0] == ' ')
			len += pf_putstr(num + 1, ft_strlen(num + 1));
		else
			len += pf_putstr(num, ft_strlen(num));
	}
	return (len);
}
