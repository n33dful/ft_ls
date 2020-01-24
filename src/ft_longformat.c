
#include "ft_ls.h"

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

static int	ft_findcolwuser(t_list *files)
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

static int	ft_findcolwgroup(t_list *files)
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

void		ft_longformat(t_list *files)
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
