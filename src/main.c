
#include "ft_ls.h"

void	ft_readdir(DIR *dir, t_flags *flags, t_list **files, t_list **queue)
{
	t_info			info;
	t_list			*new;

	while ((info.dirent = readdir(dir)) != NULL)
	{
    	stat(info.dirent->d_name, &(info.attrib));
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

char	*ft_nextFolder(char *currFolder, char *nextFolder)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin("/", nextFolder);
	res = ft_strjoin(currFolder, tmp);
	ft_strdel(&tmp);
	return (res);
}

void	del(void *content, size_t content_size)
{
	if (content_size > 0)
		ft_memdel(&content);
}

void	ft_error(char *dir_name)
{
	printf("ls: %s: %s\n", dir_name, strerror(errno));
	exit(-1);
}

void	ft_ls(char *dir_name, t_flags *flags)
{
	DIR		*dir;
	t_list	*queue;
	t_list	*stack;
	t_info	*info;
	char	*nextFoder;

	stack = NULL;
	queue = NULL;
	if (!(dir = opendir(dir_name)))
		ft_error(dir_name);
	ft_readdir(dir, flags, &stack, &queue);
	ft_sortfiles(flags, &stack, &queue);
	ft_printfiles(stack);
	ft_lstdel(&stack, del);
	while ((*flags).R && queue)
	{
		info = queue->content;
		nextFoder = ft_nextFolder(dir_name, (*info).dirent->d_name);
		printf("\n%s\n", nextFoder);
		ft_ls(nextFoder, flags);
		ft_lstmove(&queue, del);
		ft_strdel(&nextFoder);
	}
	closedir(dir);
}

int main(int argc, char **argv)
{
	t_flags	flags;

	if (!ft_setflags(argv, &flags))
		return (0);
	if (argc == 2 && argv[1][0] != '-')
		ft_ls(argv[1], &flags);
	else if (argc == 1)
		ft_ls(".", &flags);
	return (0);
}
