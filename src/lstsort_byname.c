/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:21:57 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:22:00 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	by_name_asc(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_aboutfile	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first->d_name, second->d_name) > 0)
		return (1);
	return (0);
}

int	by_name_desc(t_list *current, t_list *next)
{
	t_aboutfile	*first;
	t_aboutfile	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first->d_name, second->d_name) < 0)
		return (1);
	return (0);
}
