
#include "ft_ls.h"

unsigned short	ft_find_col_w(t_list *list)
{
	unsigned short	col_w;
	unsigned short	tmp;

	col_w = 0;
	while (list)
	{
		tmp = ft_strlen((char *)(list->content));
		if (tmp > col_w)
			col_w = tmp;
		list = list->next;
	}
	return (col_w / 8 * 8 + 8);
}

void	ft_lstprint(t_list *list)
{
    struct winsize	w;
	char			*content;
	unsigned short	i;
	unsigned short	columns;
	unsigned short	col_w;

	i = 0;
    ioctl(0, TIOCGWINSZ, &w);
	col_w = ft_find_col_w(list);
	columns = w.ws_col / col_w;
	while(list)
	{
		content = list->content;
		list = list->next;
		printf("%-*s", col_w, content);
		if (((i + 1) % columns) == 0)
			printf("\n");
		i++;
	}
	printf("\n");
}

int		sort_ascending(t_list *current, t_list *next)
{
	char	*first;
	char	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first, second) >= 0)
		return (1);
	return (0);
}

int		sort_descending(t_list *current, t_list *next)
{
	char	*first;
	char	*second;

	first = current->content;
	second = next->content;
	if (ft_strcmp(first, second) <= 0)
		return (1);
	return (0);
}

int		sort_time_ascenging(t_list *current, t_list *next)
{
    struct stat	attrib;
	char		*first;
	char		*second;
	time_t		time_first;
	time_t		time_second;

	first = current->content;
	second = next->content;
    stat(first, &attrib);
	time_first = attrib.st_mtimespec.tv_sec;
    stat(second, &attrib);
	time_second = attrib.st_mtimespec.tv_sec;
	if (time_first >= time_second)
		return (1);
	return (0);
}

int		sort_time_descenging(t_list *current, t_list *next)
{
    struct stat	attrib;
	char		*first;
	char		*second;
	time_t		time_first;
	time_t		time_second;

	first = current->content;
	second = next->content;
    stat(first, &attrib);
	time_first = attrib.st_mtimespec.tv_sec;
    stat(second, &attrib);
	time_second = attrib.st_mtimespec.tv_sec;
	if (time_first <= time_second)
		return (1);
	return (0);
}

void	del(void *content, size_t content_size)
{
	if (content_size > 0)
		ft_memdel(&content);
}

int		ft_readdir(char *dirname, t_list **list, t_queue **queue, t_flags *flags)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_list			*new;

	if(!(dirp = opendir(dirname)))
		return (0);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_name[0] == '.' && !flags->a)
			continue ;
		if (!(new = ft_lstnew(dp->d_name, ft_strlen(dp->d_name) + 1)))
		{
			ft_lstdel(list, del);
			return (0);
		}
		if (dp->d_type == 4 && dp->d_name[0] != '.' \
&& !add_to_queue(queue, create_queue_elem(dp->d_name)))
			return (0);
		ft_lstadd(list, new);
	}
	closedir(dirp);
	return (1);
}

void	ft_ls(char *dirname, t_flags *flags)
{
	char			*d_name;
	t_queue			*queue;
	t_list			*list;

	list = NULL;
	queue = NULL;
	if (!(ft_readdir(dirname, &list, &queue, flags)))
		exit(-1);
	if (flags->r && !flags->t)
		list = ft_lstsort(list, sort_descending);
	else if (!flags->r && flags->t)
		list = ft_lstsort(list, sort_time_ascenging);
	else if (flags->r && flags->t)
		list = ft_lstsort(list, sort_time_descenging);
	else
		list = ft_lstsort(list, sort_ascending);
	ft_lstprint(list);
	if (queue)
		printf("\n");
	if (flags->R && queue)
	{
		while ((d_name = next_elem_in_queue(&queue)))
		{
			printf("%s/%s:\n", dirname, d_name);
			ft_ls(d_name, flags);
			if (queue)
				printf("\n");
			ft_strdel(&d_name);
		}
	}
	ft_lstdel(&list, del);
	delete_queue(queue);
}

int main(int argc, char **argv)
{
	t_flags	*flags;

	argc = 1;
	if (!(flags = set_flags(argv)))
		return (0);
	ft_ls(".", flags);
	free(flags);
	return (0);
}
