
#include "ft_ls.h"

int			main(int argc, char **argv)
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
