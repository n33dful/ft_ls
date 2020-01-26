/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:32:31 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/02 16:33:11 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strbzero(size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_strnewf(len);
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}
