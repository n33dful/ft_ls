
#include "ft_ls.h"

static void	ft_recursively(char *direct, t_flags *flags, t_list *files)
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

static void	ft_error(char *direct)
{
	printf("ls: %s: %s\n", direct, strerror(errno));
}

void		ft_ls(char *direct, t_flags *flags)
{
	t_list	*files;

	if (!(files = ft_readdir(direct, flags)) && errno)
		return (ft_error(direct));
	ft_sortfiles(&files, flags);
	ft_printfiles(files, flags);
	if (flags->recursively)
		ft_recursively(direct, flags, files);
	ft_lstdel(&files, del);
}
