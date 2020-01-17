
#include "libft.h"

static t_list	*ft_lstswap(t_list *list)
{
	t_list	*pointer;

	pointer = list->next;
	list->next = pointer->next;
	pointer->next = list;
	return (pointer);
}

static t_list	*ft_sort(t_list *list, int (*func)(t_list *, t_list *))
{
	if (!list->next)
		return (list);
	if (func(list, list->next))
		list = ft_lstswap(list);
	list->next = ft_sort(list->next, func);
	return (list);
}

t_list			*ft_lstsort(t_list *list, int (*func)(t_list *, t_list *))
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_lstlen(list);
	while (i < len)
	{
		list = ft_sort(list, func);
		i++;
	}
	return (list);
}
