
#include "ft_ls.h"

static void		ft_printmode(t_list *file)
{
	t_info			*info;
	char			*perm;

	info = (t_info *)file->content;
	perm = ft_permissions(info);
	if ((*info).dirent->d_type == 4)
		printf("d");
	else
		printf("-");
	printf("%s", perm);
	printf(" ");
	printf(" ");
	ft_strdel(&perm);
}

static void		ft_printtime(t_list *file)
{
	char	*strtime;
	t_info	*info;

	info = file->content;
	strtime = ctime(&((*info).attrib.st_ctimespec.tv_sec));
	printf("%.3s ", strtime + 7);
	printf("%.3s ", strtime + 4);
	printf("%.5s ", strtime + 11);
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
	t_info	*info;
	int	colw;

	colw = 0;
	while (files)
	{
		info = (t_info *)files->content;
		if ((*info).attrib.st_nlink > colw)
			colw = (*info).attrib.st_nlink;
		files = files->next;
	}
	return (ft_numlen(colw));
}

static int		ft_findcolwuser(t_list *files)
{
	t_info			*info;
	struct passwd	*passwd;
	int				colw;

	colw = 0;
	while (files)
	{
		info = (t_info *)files->content;
		passwd = getpwuid((*info).attrib.st_uid);
		if ((int)ft_strlen(passwd->pw_name) > colw)
			colw = ft_strlen(passwd->pw_name);
		files = files->next;
	}
	return (colw + 1);
}

static int		ft_findcolwgroup(t_list *files)
{
	t_info			*info;
	struct group	*group;
	int				colw;

	colw = 0;
	while (files)
	{
		info = (t_info *)files->content;
		group = getgrgid((*info).attrib.st_gid);
		if ((int)ft_strlen(group->gr_name) > colw)
			colw = ft_strlen(group->gr_name);
		files = files->next;
	}
	return (colw + 1);
}

static int	ft_findcolwsize(t_list *files)
{
	t_info	*info;
	int	colw;

	colw = 0;
	while (files)
	{
		info = (t_info *)files->content;
		if ((*info).attrib.st_size > colw)
			colw = (*info).attrib.st_size;
		files = files->next;
	}
	return (ft_numlen(colw));
}

static int		ft_total(t_list *files)
{
	t_info	*info;
	int	total;

	total = 0;
	while (files)
	{
		info = (t_info *)files->content;
		total += (*info).attrib.st_blocks;
		files = files->next;
	}
	return (total);
}

static	void	ft_ell(t_list *files)
{
	t_info			*info;
	struct group	*group;
	struct passwd	*passwd;
	int				colwlinks;
	int				colwuser;
	int				colwgroup;
	int				colwsize;

	colwsize = ft_findcolwsize(files);
	colwgroup = ft_findcolwgroup(files);
	colwlinks = ft_findcolwlinks(files);
	colwuser = ft_findcolwuser(files);
	printf("total %d\n", ft_total(files));
	while (files)
	{
		info = (t_info *)files->content;
		passwd = getpwuid((*info).attrib.st_uid);
		group = getgrgid((*info).attrib.st_gid);
		ft_printmode(files);
		printf("%*d ", colwlinks, (*info).attrib.st_nlink);
		printf("%-*s", colwuser, passwd->pw_name);
		printf("%*s  ", colwgroup, group->gr_name);
		printf("%*lld", colwsize, (*info).attrib.st_size);
		ft_printtime(files);
		printf("%s\n", (*info).dirent->d_name);
		files = files->next;
	}
}

//unsigned short	ft_find_col_w(t_list *files)
//{
//	unsigned short	col_w;
//	unsigned short	tmp;
//	t_info			*info;
//
//	col_w = 0;
//	while (files)
//	{
//		info = (t_info *)files->content;
//		tmp = (*info).dirent->d_namlen;
//		if (tmp > col_w)
//			col_w = tmp;
//		files = files->next;
//	}
//	return (col_w / 8 * 8 + 8);
//}

void	ft_printfiles(t_flags *flags, t_list *files)
{
    //struct winsize	w;
	t_info			*info;
	//unsigned short	i;
	//unsigned short	columns;
	//unsigned short	col_w;

	//i = 0;
    //ioctl(0, TIOCGWINSZ, &w);
	//col_w = ft_find_col_w(files);
	//columns = w.ws_col / col_w;
	//if (columns == 0)
	//	columns = 1;
	if ((*flags).l)
		ft_ell(files);
	else
	{
		while(files)
		{
			info = (t_info *)files->content;
			//printf("%-*s", col_w, (*info).dirent->d_name);
			printf("%s\n", (*info).dirent->d_name);
			//if (((i + 1) % columns) == 0)
			//	printf("\n");
			files = files->next;
		//	i++;
		}
	}
	//if ((i % columns) != 0)
	//	printf("\n");
}
