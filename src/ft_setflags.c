
#include "ft_ls.h"

int	ft_setflags(int argc, char **argv, t_flags *flags)
{
	int	i;

	i = 1;
	flags->recursively = 0;
	flags->all = 0;
	flags->ell = 0;
	flags->reverse = 0;
	flags->time = 0;
	flags->size = 0;
	flags->single = 0;
	flags->color = 0;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--"))
			return (i + 1);
		if (argv[i][0] != '-')
			return (i);
		if (ft_strchr(argv[i], 'R'))
			flags->recursively = 1;
		if (ft_strchr(argv[i], 'a'))
			flags->all = 1;
		if (ft_strchr(argv[i], 'l'))
			flags->ell = 1;
		if (ft_strchr(argv[i], 'r'))
			flags->reverse = 1;
		if (ft_strchr(argv[i], 't'))
			flags->time = 1;
		if (ft_strchr(argv[i], 'S'))
			flags->size = 1;
		if (ft_strchr(argv[i], 'G'))
			flags->color = 1;
		i++;
	}
	return (i);
}
