
#include "ft_ls.h"

int	by_name_asc(t_list *current, t_list *next)
{
	t_about	*first;
	t_about	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first->d_name, second->d_name) >= 0)
		return (1);
	return (0);
}

int	by_name_desc(t_list *current, t_list *next)
{
	t_about	*first;
	t_about	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first->d_name, second->d_name) <= 0)
		return (1);
	return (0);
}
