
#include "ft_ls.h"

void	ft_ellgroup(int width, gid_t gid)
{
	struct group *gr;

	gr = getgrgid(gid);
	if (gr->gr_name)
		printf("%-*s", width, gr->gr_name);
	else
		printf("%-*d", width, gid);
	printf(" ");
}
