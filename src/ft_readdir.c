
#include "ft_ls.h"

static void	del(void *content, size_t content_size)
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

static int	ft_setfullpath(struct dirent *dirent, char *direct, t_about *about)
{
	if (ft_strcmp(direct, "."))
	{
		if (!(about->full_path = ft_fullpath(direct, dirent->d_name)))
			return (0);
	}
	else
		about->full_path = NULL;
	return (1);
}

static int	ft_setdirent(struct dirent *dirent, t_about *about)
{
	if (!(about->d_name = ft_strdup(dirent->d_name)))
		return (0);
	about->d_type = dirent->d_type;
	return (1);
}

static void	*ft_error(t_list **files)
{
	ft_lstdel(files, del);
	return (NULL);
}

static int	ft_setstat(struct dirent *dirent, t_about *about)
{
	struct stat		st;

	if (dirent->d_type == 10)
	{
		if ((lstat(about->full_path ? \
about->full_path : dirent->d_name, &st)) != 0)
			return (0);
	}
	else
	{
		if ((stat(about->full_path ? \
about->full_path : dirent->d_name, &st)) != 0)
			return (0);
	}
	about->st_gid = st.st_gid;
	about->st_mode = st.st_mode;
	about->st_nlink = st.st_nlink;
	about->st_uid = st.st_uid;
	about->c_time = st.st_ctimespec.tv_sec;
	about->m_time = st.st_mtimespec.tv_sec;
	about->st_size = st.st_size;
	about->st_blocks = st.st_blocks;
	return (1);
}

t_list		*ft_readdir(char *direct, t_flags *flags)
{
	DIR				*dir;
	t_list			*files;
	t_list			*new;
	t_about			about;
	struct dirent	*dirent;

	files = NULL;
	if (!(dir = opendir(direct)))
		return (NULL);
	while ((dirent = readdir(dir)) != NULL)
	{
		if (dirent->d_name[0] == '.' && !flags->a)
			continue ;
		if (!ft_setfullpath(dirent, direct, &about))
			return (ft_error(&files));
		if (!ft_setdirent(dirent, &about))
			return (ft_error(&files));
		if (!ft_setstat(dirent, &about))
			return (ft_error(&files));
		if (!(new = ft_lstnew(&about, sizeof(t_about))))
			return (ft_error(&files));
		ft_lstadd(&files, new);
	}
	closedir(dir);
	return (files);
}
