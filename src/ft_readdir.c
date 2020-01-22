
#include "ft_ls.h"

void	ft_readdir(DIR *dir, char *dir_name, t_flags *flags, t_list **files, t_list **queue)
{
	t_info			info;
	t_list			*new;

	while ((info.dirent = readdir(dir)) != NULL)
	{
		info.full_path = ft_nextFolder(dir_name, info.dirent->d_name);
		if (info.dirent->d_type == 8)
    		lstat(info.full_path, &(info.attrib));
		else
			lstat(info.full_path, &(info.attrib));
		if (info.dirent->d_name[0] == '.' && !(*flags).a)
			continue ;
		if (!(new = ft_lstnew(&info, sizeof(t_info))))
			exit(-1);
		ft_lstadd(files, ft_lstnew(&info, sizeof(t_info)));
		if ((*flags).R && info.dirent->d_type == 4 \
&& ft_strcmp(info.dirent->d_name, ".") && ft_strcmp(info.dirent->d_name, ".."))
		{
			if (!(new = ft_lstnew(&info, sizeof(t_info))))
				exit(-1);
			ft_lstadd(queue, new);
		}
	}
}
