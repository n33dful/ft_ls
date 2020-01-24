
#include "ft_ls.h"

blkcnt_t	ft_elltotal(t_list *files)
{
	t_about		*about;
	blkcnt_t	total;

	total = 0;
	while (files)
	{
		about = files->content;
		total += about->st_blocks;
		files = files->next;
	}
	return (total);
}
