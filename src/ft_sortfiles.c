
#include "ft_ls.h"

static int	sortByNameAsc(t_list *current, t_list *next)
{
	t_info	*first;
	t_info	*second;

	first = (t_info *)current->content;
	second = (t_info *)next->content;
	if (ft_strcmp((*first).dirent->d_name, (*second).dirent->d_name) >= 0)
		return (1);
	return (0);
}

static int	sortByNameDesc(t_list *current, t_list *next)
{
	t_info	*first;
	t_info	*second;

	first = (t_info *)current->content;
	second = (t_info *)next->content;
	if (ft_strcmp((*first).dirent->d_name, (*second).dirent->d_name) <= 0)
		return (1);
	return (0);
}

static int	sortByTimeAsc(t_list *current, t_list *next)
{
	t_info	*firs;
	t_info	*secd;

	firs = (t_info *)current->content;
	secd = (t_info *)next->content;
	if ((*firs).attrib.st_mtimespec.tv_sec <= (*secd).attrib.st_mtimespec.tv_sec)
		return (1);
	return (0);
}

static int	sortByTimeDesc(t_list *current, t_list *next)
{
	t_info	*firs;
	t_info	*secd;

	firs = (t_info *)current->content;
	secd = (t_info *)next->content;
	if ((*firs).attrib.st_mtimespec.tv_sec >= (*secd).attrib.st_mtimespec.tv_sec)
		return (1);
	return (0);
}

void		ft_sortfiles(t_flags *flags, t_list **files, t_list **queue)
{
	if ((*flags).r && !(*flags).t)
	{
		ft_lstsort(files, sortByNameDesc);
		ft_lstsort(queue, sortByNameDesc);
	}
	else if (!(*flags).r && (*flags).t)
	{
		ft_lstsort(files, sortByTimeAsc);
		ft_lstsort(queue, sortByTimeAsc);
	}
	else if ((*flags).r && (*flags).t)
	{
		ft_lstsort(files, sortByTimeDesc);
		ft_lstsort(queue, sortByTimeDesc);
	}
	else
	{
		ft_lstsort(files, sortByNameAsc);
		ft_lstsort(queue, sortByNameAsc);
	}
}
