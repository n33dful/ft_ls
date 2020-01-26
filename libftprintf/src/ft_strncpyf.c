/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpyf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:16:03 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:16:04 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strncpyf(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	if (len > ft_strlenf(src))
	{
		while ((unsigned char)src[i] != '\0')
		{
			dst[i] = (unsigned char)src[i];
			i++;
		}
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dst[i] = (unsigned char)src[i];
			i++;
		}
	}
	return (dst);
}
