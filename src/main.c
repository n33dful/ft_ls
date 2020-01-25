
#include "ft_ls.h"

static int	errsort(t_list *curr, t_list *next)
{
	char	*first;
	char	*second;

	first = curr->content;
	second = next->content;
	if (ft_strcmp(first, second) >= 0)
		return (1);
	return (0);
}

static void	errdel(void *content, size_t content_size)
{
	if (content_size > 0)
		ft_memdel(&content);
}

static void	ft_printerrors(t_list *lst)
{
	char	*str;

	while (lst)
	{
		str = lst->content;
		ft_printf("ls: %s: %s\n", str, strerror(2));
		lst = lst->next;
	}
}

static void	ft_errors(int argc, int index, char **argv, t_list **errlst)
{
	DIR		*dir;
	t_list	*new;
	int		i;

	i = index;
	while (i < argc)
	{
		if (!(dir = opendir(argv[i])) && (errno == ENOENT))
		{
			if (!(new = ft_lstnew(argv[i], sizeof(argv[i]))))
			{
				ft_lstdel(errlst, errdel);
				return ;
			}
			ft_lstadd(errlst, new);
		}
		if (dir)
			closedir(dir);
		i++;
	}
	ft_lstsort(errlst, errsort);
}

static t_list	*ft_singlefile(char *filename)
{
	t_about		about;
	t_list		*file;
	struct stat	st;

	if (stat(filename, &st) == 0)
		about.d_type = 0;
	else if (lstat(filename, &st) == 0)
		about.d_type = 4;
	else
		return (NULL);
	if (!(about.d_name = ft_strdup(filename)))
		return (NULL);
	about.full_path = NULL;
	about.st_gid = st.st_gid;
	about.st_mode = st.st_mode;
	about.st_nlink = st.st_nlink;
	about.st_uid = st.st_uid;
	about.c_time = st.st_ctimespec.tv_sec;
	about.m_time = st.st_mtimespec.tv_sec;
	about.st_size = st.st_size;
	about.st_blocks = st.st_blocks;
	if (!(file = ft_lstnew(&about, sizeof(t_about))))
		return (NULL);
	return (file);
}

static void	ft_single(int argc, int index, char **argv, t_flags *flags, t_list **sinlst)
{
	DIR		*dir;
	t_list	*new;
	int		i;

	i = index;
	while (i < argc)
	{
		if (!(dir = opendir(argv[i])) && (errno == ENOTDIR))
		{
			if (!(new = ft_singlefile(argv[i])))
			{
				ft_lstdel(sinlst, del);
				return ;
			}
			ft_lstadd(sinlst, new);
		}
		if (dir)
			closedir(dir);
		i++;
	}
	ft_sortfiles(sinlst, flags);
}

static void	ft_dirlst(int argc, int index, char **argv, t_list **dirs)
{
	DIR		*dir;
	t_list	*new;
	int		i;

	i = index;
	while (i < argc)
	{
		if ((dir = opendir(argv[i])))
		{
			if (!(new = ft_lstnew(argv[i], sizeof(argv[i]))))
			{
				ft_lstdel(dirs, del);
				return ;
			}
			ft_lstadd(dirs, new);
		}
		if (dir)
			closedir(dir);
		i++;
	}
	ft_lstsort(dirs, errsort);
}

static void	ft_printall(t_all *all, t_flags *flags)
{
	t_list	*point;
	size_t	count;
	size_t	size;
	
	count = 0;
	size = ft_lstlen(all->dirs);
	ft_printerrors(all->errors);
	flags->single = 1;
	ft_printfiles(all->singles, flags);
	flags->single = 0;
	point = all->dirs;
	while (point)
	{
		if (all->errors || all->singles || count < size)
			printf("\n%s:\n", (char *)all->dirs->content);
		else if (count == 0)
			printf("%s\n", (char *)all->dirs->content);
		ft_ls((char *)all->dirs->content, flags);
		point = point->next;
		count++;
	}
	ft_lstdel(&all->errors, errdel);
	ft_lstdel(&all->singles, del);
	ft_lstdel(&all->dirs, errdel);
}

int			main(int argc, char **argv)
{
	t_all	all;
	t_flags	flags;
	int		i;

	all.errors = NULL;
	all.singles = NULL;
	all.dirs = NULL;
	if ((i = ft_setflags(argc, argv, &flags)) < 0)
		return (1);
	if (i + 1 == argc)
		ft_ls(argv[i], &flags);
	else if (i < argc)
	{
		ft_errors(argc, i, argv, &all.errors);
		ft_single(argc, i, argv, &flags, &all.singles);
		ft_dirlst(argc, i, argv, &all.dirs);
		ft_printall(&all, &flags);
	}
	else
		ft_ls(".", &flags);
	return (0);
}
