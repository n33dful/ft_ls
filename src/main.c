
#include "ft_ls.h"

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
}

void	ft_ls(char *dir_name, t_flags *flags)
{
	char	*nextFoder;
	t_list	*queue;
	t_list	*stack;
	t_info	*info;
	DIR		*dir;

	stack = NULL;
	queue = NULL;
	if (!(dir = opendir(dir_name)))
		return ft_error(dir_name);
	ft_readdir(dir, flags, &stack, &queue);
	ft_sortfiles(flags, &stack, &queue);
	ft_printfiles(stack);
	ft_lstdel(&stack, del);
	closedir(dir);
	while ((*flags).R && queue)
	{
		info = queue->content;
		nextFoder = ft_nextFolder(dir_name, (*info).dirent->d_name);
		printf("\n%s\n", nextFoder);
		ft_ls(nextFoder, flags);
		ft_lstmove(&queue, del);
		ft_strdel(&nextFoder);
	}
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
