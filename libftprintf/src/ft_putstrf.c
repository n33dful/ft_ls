/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:28:59 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/26 19:42:33 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_putstrf(char const *s, size_t len)
{
	size_t	l;

	l = 0;
	if (s)
	{
		l = ft_strlenf(s);
		if (len > l)
		{
			write(1, s, l);
			return (l);
		}
		else
		{
			write(1, s, len);
			return (len);
		}
	}
	return (0);
}
