
#include "ft_ls.h"

void	ft_elltime(t_about *about)
{
	char		*strtime;

	if (time(NULL) - about->m_time > 15811200)
	{
		strtime = ctime(&(about->m_time));
		printf("%.4s", strtime + 4);
		printf("%.3s", strtime + 8);
		printf("%5.4s", strtime + 20);
	}
	else
	{
		strtime = ctime(&(about->c_time));
		printf("%.4s", strtime + 4);
		printf("%.3s", strtime + 8);
		printf("%.5s", strtime + 11);
	}
	printf(" ");
}
