
#include "ft_ls.h"

void	ft_ellgroup(int width, gid_t gid)
{
	struct group *gr;

	gr = getgrgid(gid);
	if (gr->gr_name)
		ft_printf("%-*s", width, gr->gr_name);
	else
		ft_printf("%-*d", width, gid);
	ft_printf(" ");
}
