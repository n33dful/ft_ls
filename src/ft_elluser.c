
#include "ft_ls.h"

void	ft_elluser(int width, uid_t uid)
{
	struct passwd *pass;

	pass = getpwuid(uid);
	if (pass->pw_name)
		ft_printf("%-*s", width, pass->pw_name);
	else
		ft_printf("%-*d", width, uid);
	ft_printf(" ");
}
