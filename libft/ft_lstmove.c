
#include "libft.h"

void	ft_lstmove(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;

	if (alst && del)
	{
		current = *alst;
		del(current->content, current->content_size);
		*alst = (*alst)->next;
		free(current);
		current = NULL;
	}
}
