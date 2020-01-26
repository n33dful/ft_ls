/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memallocf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:36:15 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/20 20:49:52 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memallocf(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (!(mem = malloc(size)))
		return (NULL);
	while (i < size)
		((char *)mem)[i++] = '\0';
	return (mem);
}
