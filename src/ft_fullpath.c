/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:17:12 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:17:40 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_fullpath(char *current, char *next)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin("/", next);
	res = ft_strjoin(current, tmp);
	ft_strdel(&tmp);
	return (res);
}
