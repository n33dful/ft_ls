
#include "ft_ls.h"

t_list	*ft_readdir(char *dir_name, t_flags *flags)
{
	DIR				*dir;
	t_aboutfile		about;
	t_list			*files;
	t_list			*new;
	struct dirent	*dirent;
	struct stat		st;

	files = NULL;
	dir = opendir(dir_name);
	while ((dirent = readdir(dir)) != NULL)
	{
		if (dirent->d_name[0] == '.' && !(*flags).a)
			continue ;
		if (ft_strcmp(dir_name, "."))
			about.full_path = ft_fullpath(dir_name, dirent->d_name);
		else
			about.full_path = NULL;
		if (dirent->d_type == 10)
			lstat(about.full_path ? about.full_path : dirent->d_name, &st);
		else
			stat(about.full_path ? about.full_path : dirent->d_name, &st);
		about.d_name = dirent->d_name;
		about.d_type = dirent->d_type;
		about.st_gid = st.st_gid;
		about.st_mode = st.st_mode;
		about.st_nlink = st.st_nlink;
		about.st_uid = st.st_uid;
		about.tv_sec = st.st_ctimespec.tv_sec;
		if (!(new = ft_lstnew(&about, sizeof(t_aboutfile))))
			exit(-1);
		ft_lstadd(&files, new);
	}
	closedir(dir);
	return (files);
}
