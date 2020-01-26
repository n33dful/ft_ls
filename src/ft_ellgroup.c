/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ellgroup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:16:44 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:16:47 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ellgroup(int width, gid_t gid)
{
	struct group *gr;

	gr = getgrgid(gid);
	if (gr->gr_name)
		ft_printf("%-*s", width, gr->gr_name);
	else
		ft_printf("%-*d", width, gid);
	ft_printf(" ");
}
