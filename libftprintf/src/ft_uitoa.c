/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:50:06 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/24 19:53:54 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	n_l(uintmax_t n)
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

static void	convert_to_str(uintmax_t n, uintmax_t i, char *str)
{
	str[i] = (char)(n % 10 + 48);
	i--;
	n /= 10;
	while (n != 0)
	{
		str[i] = (char)(n % 10 + 48);
		i--;
		n /= 10;
	}
}

char		*ft_uitoa(uintmax_t n)
{
	char			*str;
	int				i;
	unsigned int	size;

	size = n_l(n);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = size - 1;
	convert_to_str(n, i, str);
	str[size] = '\0';
	return (str);
}
