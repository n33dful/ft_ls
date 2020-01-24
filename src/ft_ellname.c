
#include "ft_ls.h"

void	ft_ellname(t_about *about)
{
	char	buf[1024];

	if (about->d_type == 10)
	{
		if (!(readlink(about->full_path ? \
about->full_path : about->d_name, buf, 1024)))
			printf("%s -> (null)", about->d_name);
		else
			printf("%s -> %s", about->d_name, buf);
	}
	else
		printf("%s", about->d_name);
}
