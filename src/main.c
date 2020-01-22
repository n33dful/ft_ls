
#include "ft_ls.h"

void	del(void *content, size_t content_size)
{
	t_aboutfile	*about;

	about = content;
	//ft_strdel(&((*about).full_path));
	//ft_strdel(&((*about).d_name));
	if (content_size > 0)
		ft_memdel(&content);
}

void	ft_error(char *dir_name)
{
	printf("ls: %s: %s\n", dir_name, strerror(errno));
}

void	ft_ls(char *dir_name, t_flags *flags)
{
	//char	*nextFoder;
	t_list	*files;
	//t_info	*info;
	DIR		*dir;

	if (!(dir = opendir(dir_name)))
		return ft_error(dir_name);
	files = ft_readdir(dir_name, flags);
	//ft_sortfiles(flags, &files, &queue);
	//ft_printfiles(flags, files);
	ft_lstdel(&files, del);
	//while ((*flags).R && queue)
	//{
	//	info = queue->content;
	//	nextFoder = ft_fullpath(dir_name, (*info).dirent->d_name);
	//	printf("\n%s:\n", nextFoder);
	//	ft_ls(nextFoder, flags);
	//	ft_lstmove(&queue, del);
	//	ft_strdel(&nextFoder);
	//}
	closedir(dir);
}

int main(int argc, char **argv)
{
	t_flags	flags;
	int		i;

	i = ft_setflags(argc, argv, &flags);
	if (i < argc)
	{
		while (i < argc)
		{
			if (i + 1 != argc)
				printf("%s:\n", argv[i]);
			ft_ls(argv[i], &flags);
			if (i + 1 != argc)
				printf("\n");
			i++;
		}
	}
	else
		ft_ls(".", &flags);
	return (0);
}
