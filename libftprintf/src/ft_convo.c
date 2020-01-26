/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:25:58 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/04 20:31:32 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_setcurrent(char *num, t_params *params)
{
	char *res;
	char *n;

	n = ft_strdupf(num);
	if (params->acc > (int)ft_strlenf(n))
		res = ft_strjoindelboth(ft_strbzero(params->acc - \
ft_strlenf(n)), n);
	else
	{
		if (params->altform)
			res = num;
		else
		{
			if (n[0] == '0')
				res = ft_strnewf(0);
			else
				res = n;
		}
	}
	return (res);
}

int			ft_convo(uintmax_t num, t_params *params)
{
	int		len;
	char	*tmp;
	char	*new_num;

	len = 0;
	new_num = ft_itoa_base(num, 8);
	if (params->altform && num != 0)
	{
		tmp = ft_strjoinf("0", new_num);
		ft_strdelf(&new_num);
		new_num = tmp;
	}
	if (params->acc >= 0)
		new_num = ft_setcurrent(new_num, params);
	len += ft_putn(new_num, params);
	ft_strdelf(&new_num);
	free(params);
	return (len);
}
