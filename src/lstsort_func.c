/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsort_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:21:42 by cdarci            #+#    #+#             */
/*   Updated: 2020/02/06 16:33:28 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	by_name(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_aboutfile	*second;
	t_lsflags	*flags;
	int			res;

	first = current->content;
	second = next->content;
	flags = first->flags;
	res = ft_strcmp(first->d_name, second->d_name);
	if (!flags->reverse && res > 0)
		return (1);
	else if (flags->reverse && res < 0)
		return (1);
	return (0);
}

static int	by_size(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_aboutfile	*second;
	t_lsflags	*flags;

	first = current->content;
	second = next->content;
	flags = first->flags;
	if (!flags->reverse && first->st_size < second->st_size)
		return (1);
	else if (flags->reverse && first->st_size > second->st_size)
		return (1);
	else if (first->st_size == second->st_size)
		return (by_name(current, next));
	return (0);
}

static int	by_time(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_aboutfile	*second;
	t_lsflags	*flags;

	first = current->content;
	second = next->content;
	flags = first->flags;
	if (!flags->reverse && first->m_time < second->m_time)
		return (1);
	else if (flags->reverse && first->m_time > second->m_time)
		return (1);
	else if (first->m_time == second->m_time)
		return (by_name(current, next));
	return (0);
}

int			lstsort_func(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_lsflags	*flags;

	first = current->content;
	flags = first->flags;
	if (flags->not_sorted)
		return (1);
	else if (flags->size)
		return (by_size(current, next));
	else if (flags->time)
		return (by_time(current, next));
	else
		return (by_name(current, next));
}
