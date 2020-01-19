
#include "ft_ls.h"

unsigned short	ft_find_col_w(t_list *files)
{
	unsigned short	col_w;
	unsigned short	tmp;
	t_info			*info;

	col_w = 0;
	while (files)
	{
		info = (t_info *)files->content;
		tmp = (*info).dirent->d_namlen;
		if (tmp > col_w)
			col_w = tmp;
		files = files->next;
	}
	return (col_w / 8 * 8 + 8);
}

void	ft_printfiles(t_list *files)
{
    struct winsize	w;
	t_info			*info;
	unsigned short	i;
	unsigned short	columns;
	unsigned short	col_w;

	i = 0;
    ioctl(0, TIOCGWINSZ, &w);
	col_w = ft_find_col_w(files);
	columns = w.ws_col / col_w;
	if (columns == 0)
		columns = 1;
	while(files)
	{
		info = (t_info *)files->content;
		printf("%-*s", col_w, (*info).dirent->d_name);
		if (((i + 1) % columns) == 0)
			printf("\n");
		files = files->next;
		i++;
	}
	if ((i % columns) != 0)
		printf("\n");
}
