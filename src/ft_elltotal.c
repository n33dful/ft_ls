/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elltotal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:17:01 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:17:04 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

blkcnt_t	ft_elltotal(t_list *files)
{
	t_aboutfile		*about;
	blkcnt_t	total;

	total = 0;
	while (files)
	{
		about = files->content;
		total += about->st_blocks;
		files = files->next;
	}
	return (total);
}
