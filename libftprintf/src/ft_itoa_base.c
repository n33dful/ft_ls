/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:40:24 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/30 19:37:32 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_numlen(uintmax_t num, uintmax_t base)
{
	size_t	len;

	len = 0;
	while (num / base > 0)
	{
		len++;
		num /= base;
	}
	return (len + 1);
}

char			*ft_itoa_base(uintmax_t num, uintmax_t base)
{
	char	*numstr;
	char	dig[16];
	size_t	i;

	ft_strcpyf(dig, "0123456789abcdef");
	if (!(numstr = (char *)ft_memallocf(sizeof(char) * \
ft_numlen(num, base) + 1)))
		exit(-1);
	i = 0;
	while (num >= base)
	{
		numstr[i++] = dig[num % base];
		num /= base;
	}
	numstr[i] = dig[num];
	ft_strrew(numstr);
	return (numstr);
}
