/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:16:38 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:16:41 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lstdel_func(void *content, size_t content_size)
{
	t_aboutfile	*about;

	about = NULL;
	if (content_size == 72)
	{
		about = content;
		ft_strdel(&(about->full_path));
		ft_strdel(&(about->d_name));
		ft_memdel(&content);
		about = NULL;
	}
	else
		ft_memdel(&content);
}
