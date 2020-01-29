/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elluser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:17:07 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:17:09 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_elluser(int width, uid_t uid, t_lsflags *flags)
{
	struct passwd *pass;

	pass = getpwuid(uid);
	if (pass->pw_name && !flags->numerically)
		ft_printf("%-*s", width, pass->pw_name);
	else
		ft_printf("%-*d", width, uid);
	ft_printf("  ");
}
