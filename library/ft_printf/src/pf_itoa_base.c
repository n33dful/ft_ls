/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:40:24 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/30 19:37:32 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_strrew(char *str)
{
	char	tmp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
}

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

char			*pf_itoa_base(uintmax_t num, uintmax_t base)
{
	char	*numstr;
	char	dig[16];
	size_t	i;

	ft_strcpy(dig, "0123456789abcdef");
	if (!(numstr = (char *)ft_memalloc(sizeof(char) * \
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
