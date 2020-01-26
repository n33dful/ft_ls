/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:43:31 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/30 19:24:58 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convc(int letter, t_params *params)
{
	int	len;

	len = 0;
	if (params->left)
	{
		len += ft_putcharf(letter);
		if (params->len > 1)
			len += ft_putcharntime(' ', params->len - 1);
	}
	else
	{
		if (params->len > 1)
		{
			if (params->zero)
				len += ft_putcharntime('0', params->len - 1);
			else
				len += ft_putcharntime(' ', params->len - 1);
		}
		len += ft_putcharf(letter);
	}
	free(params);
	return (len);
}
