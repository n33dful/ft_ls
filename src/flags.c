
#include "ft_ls.h"

static t_flags	*create_flags_struct()
{
	t_flags	*flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	flags->a = 0;
	flags->l = 0;
	flags->R = 0;
	flags->r = 0;
	flags->t = 0;
	return (flags);
}

t_flags			*set_flags(char **argv)
{
	t_flags	*flags;

	if (!(flags = create_flags_struct()) && argv)
		return (NULL);
	flags->R = 1;
	return(flags);
}
