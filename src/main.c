/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:21:49 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/27 19:48:07 by cdarci           ###   ########.fr       */
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

static void		lstprint_errors(t_list *lst)
{
	char	*str;

	str = lst->content;
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(2), 2);
}

static void		ft_errors(char *argv, t_list **errlst)
{
	struct stat	st;
	t_list		*new;

	if (lstat(argv, &st) != 0 && (errno == ENOENT))
	{
		if (!(new = ft_lstnew(argv, ft_strlen(argv) + 1)))
		{
			ft_lstdel(errlst, lstdel_string);
			return ;
		}
		ft_lstadd(errlst, new);
	}
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
	struct stat	stdir;
	struct stat	st;
	t_list		*new;

	if (lstat(argv, &st) == 0 && \
((st.st_mode & S_IFMT) == S_IFREG || (st.st_mode & S_IFMT) == S_IFLNK))
	{
		if ((st.st_mode & S_IFMT) == S_IFLNK && \
stat(argv, &stdir) == 0 && (stdir.st_mode & S_IFMT) == S_IFDIR)
			return ;
		if (!(new = ft_singlefile(argv)))
		{
			ft_lstdel(sinlst, lstdel_struct);
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

	if (stat(argv, &st) == 0 && (st.st_mode & S_IFMT) == S_IFDIR)
	{
		if (!(new = ft_lstnew(argv, ft_strlen(argv) + 1)))
		{
			ft_lstdel(dirs, lstdel_string);
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

	ft_lstiter(all->errors, &lstprint_errors);
	flags->single = 1;
	ft_printfiles(all->singles, flags);
	flags->single = 0;
	count = 0;
	size = ft_lstlen(all->dirs);
	point = all->dirs;
	while (point)
	{
		if (count == 0 && ((!all->singles && size != 1) || (all->errors && !all->singles)))
			ft_printf("%s:\n", point->content);
		else if (all->errors || all->singles || (count < size && size != 1))
			ft_printf("\n%s:\n", point->content);
		ft_ls(point->content, flags);
		errno = 0;
		point = point->next;
		count++;
	}
	ft_lstdel(&all->errors, lstdel_string);
	ft_lstdel(&all->singles, lstdel_struct);
	ft_lstdel(&all->dirs, lstdel_string);
}

static void		ft_allbase(t_all *all)
{
	all->errors = NULL;
	all->singles = NULL;
	all->dirs = NULL;
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
			errno = 0;
			i++;
		}
		ft_printall(&all, &flags);
	}
	else
		ft_ls(".", &flags);
	return (0);
}
