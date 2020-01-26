/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortfiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:21:42 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:21:46 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sortfiles(t_list **files, t_flags *flags)
{
	if (flags->reverse && !flags->time && !flags->size)
		ft_lstsort(files, by_name_desc);
	else if (!flags->reverse && flags->size)
		ft_lstsort(files, by_size_asc);
	else if (!flags->reverse && flags->time)
		ft_lstsort(files, by_time_asc);
	else if (flags->reverse && flags->time)
		ft_lstsort(files, by_time_desc);
	else if (flags->reverse && flags->size)
		ft_lstsort(files, by_size_desc);
	else
		ft_lstsort(files, by_name_asc);
}
