/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsort_bytime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:22:07 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/30 19:28:32 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	by_time_asc(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_aboutfile	*second;

	first = current->content;
	second = next->content;
	if (first->m_time < second->m_time)
		return (1);
	if (first->m_time == second->m_time)
		return (by_name_asc(current, next));
	return (0);
}

int	by_time_desc(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_aboutfile	*second;

	first = current->content;
	second = next->content;
	if (first->m_time > second->m_time)
		return (1);
	if (first->m_time == second->m_time)
		return (by_name_desc(current, next));
	return (0);
}
