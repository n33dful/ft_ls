/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:21:49 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:26:48 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		errsort(t_list *curr, t_list *next)
{
	char	*first;
	char	*second;

	first = curr->content;
	second = next->content;
	if (ft_strcmp(first, second) >= 0)
		return (1);
	return (0);
}

static void		errdel(void *content, size_t content_size)
{
	if (content_size > 0)
		ft_memdel(&content);
}

static void		ft_printerrors(t_list *lst)
{
	char	*str;

	while (lst)
	{
		str = lst->content;
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(2), 2);
		lst = lst->next;
	}
}

static void		ft_errors(char *argv, t_list **errlst)
{
	DIR		*dir;
	t_list	*new;

	if (!(dir = opendir(argv)) && (errno == ENOENT))
	{
		if (!(new = ft_lstnew(argv, ft_strlen(argv) + 1)))
		{
			ft_lstdel(errlst, errdel);
			return ;
		}
		ft_lstadd(errlst, new);
	}
	if (dir)
		closedir(dir);
	ft_lstsort(errlst, errsort);
}

static t_list	*ft_singlefile(char *filename)
{
	t_about		about;
	t_list		*file;
	struct stat	st;

	if (lstat(filename, &st) != 0)
		return (NULL);
	if (!(about.d_name = ft_strdup(filename)))
		return (NULL);
	about.full_path = NULL;
	about.st_gid = st.st_gid;
	about.st_mode = st.st_mode;
	about.st_nlink = st.st_nlink;
	about.st_uid = st.st_uid;
	about.c_time = st.st_ctimespec.tv_sec;
	about.m_time = st.st_mtimespec.tv_sec;
	about.st_size = st.st_size;
	about.st_blocks = st.st_blocks;
	if (!(file = ft_lstnew(&about, sizeof(t_about))))
	{
		ft_strdel(&(about.d_name));
		return (NULL);
	}
	return (file);
}

static void		ft_single(char *argv, t_flags *flags, t_list **sinlst)
{
	struct stat	st;
	t_list		*new;

	if (lstat(argv, &st) == 0 && ((st.st_mode & S_IFMT) == S_IFLNK || \
(st.st_mode & S_IFMT) == S_IFREG))
	{
		if (!(new = ft_singlefile(argv)))
		{
			ft_lstdel(sinlst, del);
			return ;
		}
		ft_lstadd(sinlst, new);
	}
	ft_sortfiles(sinlst, flags);
}

static void		ft_dirlst(char *argv, t_list **dirs)
{
	struct stat	st;
	t_list		*new;

	if (lstat(argv, &st) == 0 && (st.st_mode & S_IFMT) == S_IFDIR)
	{
		if (!(new = ft_lstnew(argv, ft_strlen(argv) + 1)))
		{
			ft_lstdel(dirs, errdel);
			return ;
		}
		ft_lstadd(dirs, new);
	}
	ft_lstsort(dirs, errsort);
}

static void		ft_printall(t_all *all, t_flags *flags)
{
	t_list	*point;
	size_t	count;
	size_t	size;

	count = 0;
	size = ft_lstlen(all->dirs);
	ft_printerrors(all->errors);
	flags->single = 1;
	ft_printfiles(all->singles, flags);
	flags->single = 0;
	point = all->dirs;
	while (point)
	{
		if (count == 0 && !all->errors && !all->singles && size != 1)
			ft_printf("%s:\n", point->content);
		else if (all->errors || all->singles || (count < size && size != 1))
			ft_printf("\n%s:\n", point->content);
		ft_ls(point->content, flags);
		point = point->next;
		count++;
	}
	count = 0;
	size = ft_lstlen(all->denied);
	point = all->denied;
	while (point)
	{
		if (count == 0 && !all->errors && !all->singles && size != 1)
			ft_printf("%s:\n", point->content);
		else if (all->errors || all->singles || (count < size && size != 1))
			ft_printf("\n%s:\n", point->content);
		ft_ls(point->content, flags);
		point = point->next;
		count++;
	}
	ft_lstdel(&all->errors, errdel);
	ft_lstdel(&all->singles, del);
	ft_lstdel(&all->dirs, errdel);
	ft_lstdel(&all->denied, errdel);
}

static void		ft_denied(char *argv, t_list **dirs)
{
	DIR		*dir;
	t_list	*new;

	if (!(dir = opendir(argv)) && errno == EACCES)
	{
		if (!(new = ft_lstnew(argv, sizeof(argv))))
		{
			ft_lstdel(dirs, errdel);
			return ;
		}
		ft_lstadd(dirs, new);
	}
	if (dir)
		closedir(dir);
	ft_lstsort(dirs, errsort);
}

static void		ft_allbase(t_all *all)
{
	all->errors = NULL;
	all->singles = NULL;
	all->dirs = NULL;
	all->denied = NULL;
}

int				main(int argc, char **argv)
{
	t_all	all;
	t_flags	flags;
	int		i;

	ft_allbase(&all);
	if ((i = ft_setflags(argc, argv, &flags)) < 0)
		return (1);
	else if (i < argc)
	{
		while (i < argc)
		{
			ft_errors(argv[i], &all.errors);
			ft_single(argv[i], &flags, &all.singles);
			ft_dirlst(argv[i], &all.dirs);
			ft_denied(argv[i], &all.denied);
			errno = 0;
			i++;
		}
		ft_printall(&all, &flags);
	}
	else
		ft_ls(".", &flags);
	return (0);
}
