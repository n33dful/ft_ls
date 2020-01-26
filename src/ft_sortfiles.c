
#include "ft_ls.h"

void	ft_sortfiles(t_list **files, t_flags *flags)
{
	if (flags->reverse && !flags->time && !flags->size)
		ft_lstsort(files, by_name_desc);
	else if (!flags->reverse && flags->size)
		ft_lstsort(files, by_size_asc);
	else if (!flags->reverse && flags->time)
		ft_lstsort(files, by_time_asc);
	else if (flags->reverse && flags->time)
		ft_lstsort(files, by_time_desc);
	else if (flags->reverse && flags->size)
		ft_lstsort(files, by_size_desc);
	else
		ft_lstsort(files, by_name_asc);
}
