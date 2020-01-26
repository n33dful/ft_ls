/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:46:13 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/02 16:46:43 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_spec(char *num, t_params *params)
{
	int	len;

	len = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		if (num[0] == '-')
			len += ft_putcharf('-');
		else if (num[0] == '+')
			len += ft_putcharf('+');
		len += ft_putcharntime('0', params->len - (int)ft_strlenf(num));
		len += ft_putstrf(num + 1, ft_strlenf(num) - 1);
	}
	else
	{
		if (num[0] == ' ')
			len += ft_putcharf(' ');
		len += ft_putcharntime('0', params->len - (int)ft_strlenf(num));
		if (num[0] == ' ')
			len += ft_putstrf(num + 1, ft_strlenf(num + 1));
		else
			len += ft_putstrf(num, ft_strlenf(num));
	}
	return (len);
}
