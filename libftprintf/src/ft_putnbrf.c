/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:06:34 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/22 19:06:55 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbrf(int n)
{
	int		count;
	char	*num;

	count = 0;
	num = ft_itoaf(n);
	count += ft_putstrf(num, ft_strlenf(num));
	ft_strdelf(&num);
	return (count);
}
