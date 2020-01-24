
#include "ft_ls.h"

void	ft_printfiles(t_list *files, t_flags *flags)
{
	t_about			*about;

	if (flags->ell)
		ft_longformat(files);
	else
	{
		while (files)
		{
			about = files->content;
			printf("%s\n", about->d_name);
			files = files->next;
		}
	}
}
