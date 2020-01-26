/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:20:39 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/24 19:22:50 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	n_l(intmax_t n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	convert_to_str(intmax_t n, intmax_t i, char *str)
{
	if (n % 10 < 0)
		str[i] = (char)(-1 * (n % 10) % 10 + 48);
	else
		str[i] = (char)(n % 10 + 48);
	i--;
	n /= 10;
	while (n != 0)
	{
		if (n % 10 < 0)
			str[i] = (char)(-1 * (n % 10) % 10 + 48);
		else
			str[i] = (char)(n % 10 + 48);
		i--;
		n /= 10;
	}
}

char		*ft_itoaf(intmax_t n)
{
	char			*str;
	int				i;
	unsigned int	size;

	size = n_l(n);
	if (!(str = (char *)malloc(sizeof(char) * size + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		size++;
	}
	i = size - 1;
	convert_to_str(n, i, str);
	str[size] = '\0';
	return (str);
}
