
#include "ft_ls.h"

static int	by_name_asc(t_list *current, t_list *next)
{
	t_about	*first;
	t_about	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first->d_name, second->d_name) >= 0)
		return (1);
	return (0);
}

static int	by_name_desc(t_list *current, t_list *next)
{
	t_about	*first;
	t_about	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first->d_name, second->d_name) <= 0)
		return (1);
	return (0);
}

static int	by_time_asc(t_list *current, t_list *next)
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

static int	by_time_desc(t_list *current, t_list *next)
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

void		ft_sortfiles(t_list **files, t_flags *flags)
{
	if (flags->r && !flags->t)
		ft_lstsort(files, by_name_desc);
	else if (!flags->r && flags->t)
		ft_lstsort(files, by_time_asc);
	else if (flags->r && flags->t)
		ft_lstsort(files, by_time_desc);
	else
		ft_lstsort(files, by_name_asc);
}
