/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setbasicflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:29:34 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/30 19:47:23 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_printf	*pf_setbasicflags(void)
{
	t_printf *params;

	if (!(params = (t_printf *)malloc(sizeof(t_printf))))
	{
		pf_putstr("error to alocate the memory!\n", 29);
		exit(EXIT_FAILURE);
	}
	params->len = 0;
	params->left = 0;
	params->acc = -1;
	params->altform = 0;
	params->space = 0;
	params->sign = 0;
	params->zero = 0;
	params->flagl = 0;
	params->flagh = 0;
	params->flagld = 0;
	return (params);
}
