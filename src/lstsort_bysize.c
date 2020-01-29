/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:22:02 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:22:04 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	by_size_asc(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_aboutfile	*second;

	first = current->content;
	second = next->content;
	if (first->st_size < second->st_size)
		return (1);
	if (first->st_size == second->st_size)
		return (by_name_asc(current, next));
	return (0);
}

int	by_size_desc(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_aboutfile	*second;

	first = current->content;
	second = next->content;
	if (first->st_size > second->st_size)
		return (1);
	if (first->st_size == second->st_size)
		return (by_name_desc(current, next));
	return (0);
}
