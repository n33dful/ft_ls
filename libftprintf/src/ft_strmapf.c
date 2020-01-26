/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:06:04 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/20 20:49:52 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strmapf(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * ft_strlenf(s) + 1)))
		return (NULL);
	while (s[i])
	{
		fresh[i] = f(s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
