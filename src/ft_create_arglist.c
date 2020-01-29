
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

static t_list	*ft_singlefile(char *filename)
{
	t_aboutfile		about;
	t_list		*file;
	struct stat	st;

	if (lstat(filename, &st) != 0)
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
			ft_lstdel(errlst, lstdel_string);
			return ;
		}
		ft_lstadd_back(errlst, new);
	}
	ft_lstsort(errlst, errsort);
	errno = 0;
}

void			ft_create_file_list(char *argv, t_lsflags *flags, t_list **sinlst)
{
	struct stat	stdir;
	struct stat	st;
	t_list		*new;

	if (lstat(argv, &st) == 0 && \
((st.st_mode & S_IFMT) == S_IFREG || (st.st_mode & S_IFMT) == S_IFLNK))
	{
		if ((st.st_mode & S_IFMT) == S_IFLNK && \
stat(argv, &stdir) == 0 && (stdir.st_mode & S_IFMT) == S_IFDIR)
			return ;
		if (!(new = ft_singlefile(argv)))
		{
			ft_lstdel(sinlst, lstdel_struct);
			return ;
		}
		ft_lstadd_back(sinlst, new);
	}
	ft_sortfiles(sinlst, flags);
	errno = 0;
}

void			ft_create_folder_list(char *argv, t_list **dirs)
{
	struct stat	st;
	t_list		*new;

	if (stat(argv, &st) == 0 && (st.st_mode & S_IFMT) == S_IFDIR)
	{
		if (!(new = ft_lstnew(argv, ft_strlen(argv) + 1)))
		{
			ft_lstdel(dirs, lstdel_string);
			return ;
		}
		ft_lstadd_back(dirs, new);
	}
	ft_lstsort(dirs, errsort);
	errno = 0;
}
