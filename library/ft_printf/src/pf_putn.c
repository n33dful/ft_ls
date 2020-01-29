/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:52:47 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/02 19:55:38 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putn(char *num, t_printf *params)
{
	int	len;

	len = 0;
	if (params->left)
		if (params->len > ft_strlen(num))
		{
			len += pf_putstr(num, ft_strlen(num));
			len += pf_putcharntime(' ', params->len - (int)ft_strlen(num));
		}
		else
			len += pf_putstr(num, ft_strlen(num));
	else
	{
		if (params->len > ft_strlen(num))
			if (params->zero && params->acc == -1)
				len += pf_spec(num, params);
			else
			{
				len += pf_putcharntime(' ', params->len - (int)ft_strlen(num));
				len += pf_putstr(num, ft_strlen(num));
			}
		else
			len += pf_putstr(num, ft_strlen(num));
	}
	return (len);
}
