/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:39:42 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/20 20:49:52 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdupf(const char *s1)
{
	int		lenght;
	char	*link;
	int		i;

	i = 0;
	lenght = ft_strlenf(s1);
	link = (char*)malloc(sizeof(char) * lenght + 1);
	if (link != NULL)
	{
		while (s1[i] != '\0')
		{
			link[i] = s1[i];
			i++;
		}
		link[i] = '\0';
		return (link);
	}
	return (NULL);
}
