
#include "ft_ls.h"

int	ft_setflags(int argc, char **argv, t_flags *flags)
{
	int	i;

	i = 1;
	flags->R = 0;
	flags->a = 0;
	flags->l = 0;
	flags->r = 0;
	flags->t = 0;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--"))
			return (i + 1);
		if (argv[i][0] != '-')
			return (i);
		if (ft_strchr(argv[i], 'R'))
			flags->R = 1;
		if (ft_strchr(argv[i], 'a'))
			flags->a = 1;
		if (ft_strchr(argv[i], 'l'))
			flags->l = 1;
		if (ft_strchr(argv[i], 'r'))
			flags->r = 1;
		if (ft_strchr(argv[i], 't'))
			flags->t = 1;
		i++;
	}
	return (i);
}
