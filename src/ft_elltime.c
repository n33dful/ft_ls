/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elltime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:16:56 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/27 16:06:52 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_elltime(t_about *about)
{
	char		*strtime;

	strtime = ctime(&(about->m_time));
	strtime[ft_strlen(strtime) - 1] = '\0';
	ft_printf("%.4s", strtime + 4);
	ft_printf("%.3s", strtime + 8);
	if (time(NULL) - about->m_time > 15811200)
		ft_printf("%5.4s", strtime + 20);
	else if (time(NULL) - about->m_time < 0)
		ft_printf(" %s", ft_strrchr(strtime, ' ') + 1);
	else
		ft_printf("%.5s", strtime + 11);
	ft_printf(" ");
}
