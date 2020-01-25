
#include "ft_ls.h"

void	ft_ellname(t_about *about, t_flags *flags)
{
	char	buf[1024];
	ssize_t	rs;

	rs = readlink(about->full_path ? about->full_path : about->d_name, buf, 1024);
	if (rs && flags->color && (about->st_mode & S_IFLNK) == 0120000)
		ft_printf("\033[35m%s\033[0m -> %s", about->d_name, buf);
	else if (rs && !flags->color && (about->st_mode & S_IFLNK) == 0120000)
		ft_printf("%s -> %s", about->d_name, buf);
	else if (flags->color && (about->st_mode & S_IFDIR) == 0040000)
		ft_printf("\033[34m%s\033[0m", about->d_name);
	else if (flags->color && (about->st_mode & S_IXUSR) == 0000100)
		ft_printf("\033[31m%s\033[0m", about->d_name);
	else
		ft_printf("%s", about->d_name);
}
