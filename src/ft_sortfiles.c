
#include "ft_ls.h"

static int	sortByNameAsc(t_list *current, t_list *next)
{
	t_about	*first;
	t_about	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first->d_name, second->d_name) >= 0)
		return (1);
	return (0);
}

static int	sortByNameDesc(t_list *current, t_list *next)
{
	t_about	*first;
	t_about	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first->d_name, second->d_name) <= 0)
		return (1);
	return (0);
}

static int	sortByTimeAsc(t_list *current, t_list *next)
{
	t_about	*first;
	t_about	*second;

	first = current->content;
	second = next->content;
	if (first->m_time < second->m_time)
		return (1);
	if (first->m_time == second->m_time)
		return (sortByNameDesc(current, next));
	return (0);
}

static int	sortByTimeDesc(t_list *current, t_list *next)
{
	t_about	*first;
	t_about	*second;

	first = current->content;
	second = next->content;
	if (first->m_time > second->m_time)
		return (1);
	if (first->m_time == second->m_time)
		return (sortByNameAsc(current, next));
	return (0);
}

void		ft_sortfiles(t_list **files, t_flags *flags)
{
	if (flags->r && !flags->t)
		ft_lstsort(files, sortByNameDesc);
	else if (!flags->r && flags->t)
		ft_lstsort(files, sortByTimeAsc);
	else if (flags->r && flags->t)
		ft_lstsort(files, sortByTimeDesc);
	else
		ft_lstsort(files, sortByNameAsc);
}
