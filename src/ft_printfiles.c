
#include "ft_ls.h"

static void		ft_ellmode(t_about *about)
{
	if (about->d_type == 4)
		printf("d");
	else if (about->d_type == 10)
		printf("l");
	else
		printf("-");
	printf("%c", (about->st_mode & S_IRUSR) ? 'r' : '-');
	printf("%c", (about->st_mode & S_IWUSR) ? 'w' : '-');
	printf("%c", (about->st_mode & S_IXUSR) ? 'x' : '-');
	printf("%c", (about->st_mode & S_IRGRP) ? 'r' : '-');
	printf("%c", (about->st_mode & S_IWGRP) ? 'w' : '-');
	printf("%c", (about->st_mode & S_IXGRP) ? 'x' : '-');
	printf("%c", (about->st_mode & S_IROTH) ? 'r' : '-');
	printf("%c", (about->st_mode & S_IWOTH) ? 'w' : '-');
	printf("%c", (about->st_mode & S_IXOTH) ? 'x' : '-');
	printf(" ");
	printf(" ");
}

static void		ft_elltime(t_about *about)
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

static	int	ft_numlen(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static int	ft_findcolwlinks(t_list *files)
{
	t_about	*about;
	int		colw;

	colw = 0;
	while (files)
	{
		about = files->content;
		if (about->st_nlink > colw)
			colw = about->st_nlink;
		files = files->next;
	}
	return (ft_numlen(colw));
}

static int		ft_findcolwuser(t_list *files)
{
	t_about			*about;
	struct passwd	*passwd;
	int				colw;

	colw = 0;
	while (files)
	{
		about = files->content;
		passwd = getpwuid(about->st_uid);
		if (passwd->pw_name)
		{
			if ((int)ft_strlen(passwd->pw_name) > colw)
				colw = ft_strlen(passwd->pw_name);
		}
		else
		{
			if (ft_numlen(about->st_uid) > colw)
				colw = ft_numlen(about->st_uid);
		}
		files = files->next;
	}
	return (colw + 1);
}

static int		ft_findcolwgroup(t_list *files)
{
	t_about			*about;
	struct group	*group;
	int				colw;

	colw = 0;
	while (files)
	{
		about = files->content;
		group = getgrgid(about->st_gid);
		if (group->gr_name)
		{
			if ((int)ft_strlen(group->gr_name) > colw)
				colw = ft_strlen(group->gr_name);
		}
		else
		{
			if (ft_numlen(about->st_gid) > colw)
				colw = ft_numlen(about->st_gid);
		}
		files = files->next;
	}
	return (colw + 1);
}

static int	ft_findcolwsize(t_list *files)
{
	t_about	*about;
	int		colw;

	colw = 0;
	while (files)
	{
		about = files->content;
		if (about->st_size > colw)
			colw = about->st_size;
		files = files->next;
	}
	return (ft_numlen(colw));
}

static blkcnt_t	ft_elltotal(t_list *files)
{
	t_about		*about;
	blkcnt_t	total;

	total = 0;
	while (files)
	{
		about = files->content;
		total += about->st_blocks;
		files = files->next;
	}
	return (total);
}

static void		ft_ellname(t_about *about)
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

static void		ft_elluser(int width, uid_t uid)
{
	struct passwd *pass;

	pass = getpwuid(uid);
	if (pass->pw_name)
		printf("%-*s", width, pass->pw_name);
	else
		printf("%-*d", width, uid);
	printf(" ");
}

static void		ft_ellgroup(int width, gid_t gid)
{
	struct group *gr;

	gr = getgrgid(gid);
	if (gr->gr_name)
		printf("%-*s", width, gr->gr_name);
	else
		printf("%-*d", width, gid);
	printf(" ");
}

static	void	ft_ell(t_list *files)
{
	t_about			*about;
	int				uwidth;
	int				gwidth;
	int				lwidth;
	int				swidth;

	swidth = ft_findcolwsize(files);
	lwidth = ft_findcolwlinks(files);
	uwidth = ft_findcolwuser(files);
	gwidth = ft_findcolwgroup(files);
	if (ft_lstlen(files) > 1)
		printf("total %lld\n", ft_elltotal(files));
	while (files)
	{
		about = files->content;
		ft_ellmode(about);
		printf("%*d ", lwidth, about->st_nlink);
		ft_elluser(uwidth, about->st_uid);
		ft_ellgroup(gwidth, about->st_gid);
		printf("%*lld ", swidth, about->st_size);
		ft_elltime(about);
		ft_ellname(about);
		printf("\n");
		files = files->next;
	}
}

void	ft_printfiles(t_list *files, t_flags *flags)
{
	t_about			*about;

	if (flags->l)
		ft_ell(files);
	else
	{
		while (files)
		{
			about = files->content;
			printf("%s\n", about->d_name);
			files = files->next;
		}
	}
}
