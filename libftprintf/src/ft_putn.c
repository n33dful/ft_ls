/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:52:47 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/02 19:55:38 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putn(char *num, t_params *params)
{
	int	len;

	len = 0;
	if (params->left)
		if (params->len > ft_strlenf(num))
		{
			len += ft_putstrf(num, ft_strlenf(num));
			len += ft_putcharntime(' ', params->len - (int)ft_strlenf(num));
		}
		else
			len += ft_putstrf(num, ft_strlenf(num));
	else
	{
		if (params->len > ft_strlenf(num))
			if (params->zero && params->acc == -1)
				len += ft_spec(num, params);
			else
			{
				len += ft_putcharntime(' ', params->len - (int)ft_strlenf(num));
				len += ft_putstrf(num, ft_strlenf(num));
			}
		else
			len += ft_putstrf(num, ft_strlenf(num));
	}
	return (len);
}
