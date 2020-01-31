
#include "ft_ls.h"

static int		errsort(t_list *curr, t_list *next)
{
	char	*first;
	char	*second;

	first = curr->content;
	second = next->content;
	if (ft_strcmp(first, second) >= 0)
		return (1);
	return (0);
}

static t_list	*ft_singlefile(char *filename, t_lsflags *flags)
{
	t_aboutfile	about;
	t_list		*file;
	struct stat	st;

	if (lstat(filename, &st) != 0)
		return (NULL);
	if (!(about.d_name = ft_strdup(filename)))
		return (NULL);
	about.full_path = NULL;
	ft_statcpy(&about, flags, &st);
	if (!(file = ft_lstnew(&about, sizeof(t_aboutfile))))
	{
		ft_strdel(&(about.d_name));
		return (NULL);
	}
	return (file);
}

void			ft_create_error_list(char *argv, t_list **errlst)
{
	struct stat	st;
	t_list		*new;

	if (lstat(argv, &st) != 0 && (errno == ENOENT))
	{
		if (!(new = ft_lstnew(argv, ft_strlen(argv) + 1)))
		{
			ft_lstdel(errlst, lstdel_func);
			return ;
		}
		ft_lstadd_back(errlst, new);
	}
	ft_lstsort(errlst, errsort);
	errno = 0;
}

void			ft_create_file_list(char *argv, t_lsflags *flags, \
t_list **sinlst)
{
	struct stat	stdir;
	struct stat	st;
	t_list		*new;

	if (lstat(argv, &st) == 0 && \
((st.st_mode & S_IFMT) == S_IFREG || (st.st_mode & S_IFMT) == S_IFLNK))
	{
		if ((st.st_mode & S_IFMT) == S_IFLNK && \
stat(argv, &stdir) == 0 && (stdir.st_mode & S_IFMT) == S_IFDIR && !flags->ell)
			return ;
		if (!(new = ft_singlefile(argv, flags)))
		{
			ft_lstdel(sinlst, lstdel_func);
			return ;
		}
		ft_lstadd_back(sinlst, new);
	}
	ft_lstsort(sinlst, lstsort_func);
	errno = 0;
}

void			ft_create_folder_list(char *argv, t_lsflags *flags, \
t_list **dirs)
{
	struct stat	st;
	t_list		*new;

	if (stat(argv, &st) == 0 && (st.st_mode & S_IFMT) == S_IFDIR)
	{
		lstat(argv, &st);
		if ((st.st_mode & S_IFMT) == S_IFLNK && flags->ell)
			return ;
		if (!(new = ft_lstnew(argv, ft_strlen(argv) + 1)))
		{
			ft_lstdel(dirs, lstdel_func);
			return ;
		}
		ft_lstadd_back(dirs, new);
	}
	ft_lstsort(dirs, errsort);
	errno = 0;
}
