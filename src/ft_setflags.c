
#include "ft_ls.h"

int	ft_setflags(char **argv, t_flags *flags)
{
	if (!argv)
	{
		(*flags) = (*flags);
		(*flags).R = 1;
		(*flags).a = 0;
		(*flags).l = 0;
		(*flags).r = 0;
		(*flags).t = 0;
	}
	else
	{
		(*flags) = (*flags);
		(*flags).R = 1;
		(*flags).a = 0;
		(*flags).l = 0;
		(*flags).r = 0;
		(*flags).t = 0;
	}
	return (1);
}
