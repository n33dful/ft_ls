/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:29:49 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/16 17:39:51 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_addtail(t_list **alst, t_list *new_lst)
{
	t_list *pointer;

	pointer = (*alst);
	if (pointer && new_lst)
	{
		while (pointer->next)
			pointer = pointer->next;
		pointer->next = new_lst;
	}
}

static t_list	*ft_listdel(t_list **list)
{
	t_list	*next_elem;

	while ((*list))
	{
		next_elem = (*list)->next;
		if ((*list)->content)
			free((*list)->content);
		free((*list));
		(*list) = next_elem;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;

	if (!lst || !f || !(head = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	head = f(lst);
	head->next = NULL;
	lst = lst->next;
	while (lst)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (ft_listdel(&head));
		new = f(lst);
		new->next = NULL;
		ft_addtail(&head, new);
		lst = lst->next;
	}
	return (head);
}
