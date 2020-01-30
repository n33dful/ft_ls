/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:17:46 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/30 19:29:34 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_findcolwlinks(t_list *files)
{
	t_aboutfile	*about;
	int			colw;

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

static int	ft_findcolwuser(t_list *files, t_lsflags *flags)
{
	t_aboutfile		*about;
	struct passwd	*passwd;
	int				colw;

	colw = 0;
	while (files)
	{
		about = files->content;
		passwd = getpwuid(about->st_uid);
		if (passwd->pw_name && !flags->numerically)
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
	return (colw);
}

static int	ft_findcolwgroup(t_list *files, t_lsflags *flags)
{
	t_aboutfile		*about;
	struct group	*group;
	int				colw;

	colw = 0;
	while (files)
	{
		about = files->content;
		group = getgrgid(about->st_gid);
		if (group->gr_name && !flags->numerically)
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
	return (colw);
}

static int	ft_findcolwsize(t_list *files)
{
	t_aboutfile	*about;
	int			colw;

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

void		ft_longformat(t_list *files, t_lsflags *flags)
{
	t_aboutfile	*about;
	int			uwidth;
	int			gwidth;
	int			lwidth;
	int			swidth;

	swidth = ft_findcolwsize(files);
	lwidth = ft_findcolwlinks(files);
	uwidth = ft_findcolwuser(files, flags);
	gwidth = ft_findcolwgroup(files, flags);
	if (!flags->single && ft_lstlen(files) != 0)
		ft_printf("total %lld\n", ft_elltotal(files));
	while (files)
	{
		about = files->content;
		ft_ellmode(about);
		ft_printf("%*d ", lwidth, about->st_nlink);
		if (!flags->group_only)
			ft_elluser(uwidth, about->st_uid, flags);
		if (!flags->user_only)
			ft_ellgroup(gwidth, about->st_gid, flags);
		if (flags->group_only && flags->user_only)
			ft_printf("  ");
		ft_printf("%*lld ", swidth, about->st_size);
		ft_elltime(about);
		ft_ellname(about, flags);
		files = files->next;
	}
}
