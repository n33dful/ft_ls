
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

void	ft_error(char *direct)
{
	printf("ls: %s: %s\n", direct, strerror(errno));
}

void	ft_recurs(char *direct, t_flags *flags, t_list *files)
{
	char	*nextdirect;
	t_about	*about;

	while (files)
	{
		about = files->content;
		if (about->d_type == 4 && \
ft_strcmp(about->d_name, ".") && ft_strcmp(about->d_name, ".."))
		{
			nextdirect = ft_fullpath(direct, about->d_name);
			printf("\n%s:\n", nextdirect);
			ft_ls(nextdirect, flags);
			ft_strdel(&nextdirect);
		}
		files = files->next;
	}
}

void	ft_ls(char *direct, t_flags *flags)
{
	t_list	*files;

	if (!(files = ft_readdir(direct, flags)) && errno)
		return (ft_error(direct));
	ft_sortfiles(&files, flags);
	ft_printfiles(files, flags);
	if (flags->R)
		ft_recurs(direct, flags, files);
	ft_lstdel(&files, del);
}

int main(int argc, char **argv)
{
	t_flags	flags;
	int		i;

	if ((i = ft_setflags(argc, argv, &flags)) < 0)
		return (1);
	if (i + 1 == argc)
		ft_ls(argv[i], &flags);
	else if (i < argc)
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
