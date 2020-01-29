
#include "libft.h"

void	ft_lstaddtail(t_list **alst, t_list *new)
{
	t_list	*point;

	point = (*alst);
	if (!point)
	{
		(*alst) = new;
		return ;
	}
	while (point->next)
		point = point->next;
	point->next = new;
}
