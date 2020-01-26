/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindelsecond.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:25:38 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/21 18:26:10 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoindelsecond(char const *s1, char *s2)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = ft_strnewf(ft_strlenf(s1) + ft_strlenf(s2))))
		return (NULL);
	ft_strcpyf(str, s1);
	ft_strcpyf(str + ft_strlenf(s1), s2);
	ft_strdelf(&s2);
	return (str);
}
