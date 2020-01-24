
#include "ft_ls.h"

void	del(void *content, size_t content_size)
{
	t_about	*about;

	about = NULL;
	if (content_size > 0)
	{
		about = content;
		ft_strdel(&(about->full_path));
		ft_strdel(&(about->d_name));
		ft_memdel(&content);
		about = NULL;
	}
}
