/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elltime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:16:56 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:16:58 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_elltime(t_about *about)
{
	char		*strtime;

	if (time(NULL) - about->m_time > 15811200)
	{
		strtime = ctime(&(about->m_time));
		ft_printf("%.4s", strtime + 4);
		ft_printf("%.3s", strtime + 8);
		ft_printf("%5.4s", strtime + 20);
	}
	else
	{
		strtime = ctime(&(about->m_time));
		ft_printf("%.4s", strtime + 4);
		ft_printf("%.3s", strtime + 8);
		ft_printf("%.5s", strtime + 11);
	}
	ft_printf(" ");
}
