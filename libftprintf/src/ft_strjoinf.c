/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:05:32 by cdarci            #+#    #+#             */
/*   Updated: 2019/10/21 18:27:03 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoinf(char const *s1, char const *s2)
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
	return (str);
}
