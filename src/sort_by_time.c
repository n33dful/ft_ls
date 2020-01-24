
#include "ft_ls.h"

int	by_time_asc(t_list *current, t_list *next)
{
	t_about	*first;
	t_about	*second;

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
	t_about	*first;
	t_about	*second;

	first = current->content;
	second = next->content;
	if (first->m_time > second->m_time)
		return (1);
	if (first->m_time == second->m_time)
		return (by_name_desc(current, next));
	return (0);
}
