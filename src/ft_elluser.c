
#include "ft_ls.h"

void	ft_elluser(int width, uid_t uid)
{
	struct passwd *pass;

	pass = getpwuid(uid);
	if (pass->pw_name)
		printf("%-*s", width, pass->pw_name);
	else
		printf("%-*d", width, uid);
	printf(" ");
}
