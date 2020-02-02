/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:18:35 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/30 19:27:11 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_findcolwidths(t_list *file)
{
	t_aboutfile		*about;
	t_lsflags		*flags;
	t_table			*table;
	struct passwd	*passwd;
	struct group	*group;

	about = file->content;
	flags = about->flags;
	table = flags->talbe_width;
	if (ft_numlen(about->st_size) > table->filesize_colwidth)
		table->filesize_colwidth = ft_numlen(about->st_size);
	if (ft_numlen(about->st_nlink) > table->links_colwidth)
		table->links_colwidth = ft_numlen(about->st_nlink);
	if ((group = getgrgid(about->st_gid)) && group->gr_name && \
!flags->numerically && (int)ft_strlen(group->gr_name) > table->group_colwidth)
		table->group_colwidth = ft_strlen(group->gr_name);
	else if (ft_numlen(about->st_gid) > table->group_colwidth)
		table->group_colwidth = ft_numlen(about->st_gid);
	if ((passwd = getpwuid(about->st_uid)) && passwd->pw_name && \
!flags->numerically && (int)ft_strlen(passwd->pw_name) > table->user_colwidth)
		table->user_colwidth = ft_strlen(passwd->pw_name);
	else if (ft_numlen(about->st_uid) > table->user_colwidth)
		table->user_colwidth = ft_numlen(about->st_uid);
	table->total_blkcntsize += about->st_blocks;
}

static void	lstprint_inlong(t_list *file)
{
	t_aboutfile	*about;
	t_lsflags	*flags;
	t_table		*table;

	about = file->content;
	flags = about->flags;
	table = flags->talbe_width;
	ft_ellmode(about);
	ft_printf("%*d ", table->links_colwidth, about->st_nlink);
	if (!flags->group_only)
		ft_elluser(table->user_colwidth, about->st_uid, flags);
	if (!flags->user_only)
		ft_ellgroup(table->group_colwidth, about->st_gid, flags);
	if (flags->group_only && flags->user_only)
		ft_printf("  ");
	ft_printf("%*lld ", table->filesize_colwidth, about->st_size);
	ft_elltime(about);
	ft_ellname(file);
}

static void	lstprint_inline(t_list *file)
{
	ft_printfilename(file);
	ft_printf("\n");
}

static void	ft_nullifytable(t_table *table)
{
	table->filesize_colwidth = 0;
	table->group_colwidth = 0;
	table->links_colwidth = 0;
	table->user_colwidth = 0;
	table->total_blkcntsize = 0;
}

void		ft_printfiles(t_list *files)
{
	t_aboutfile	*about;
	t_lsflags	*flags;
	t_table		table;

	if (!files)
		return ;
	ft_nullifytable(&table);
	about = files->content;
	flags = about->flags;
	flags->talbe_width = &table;
	if (flags->ell)
	{
		ft_lstiter(files, ft_findcolwidths);
		if (!flags->single && ft_lstlen(files) != 0)
			ft_printf("total %lld\n", table.total_blkcntsize);
		ft_lstiter(files, lstprint_inlong);
	}
	else
		ft_lstiter(files, lstprint_inline);
	flags->talbe_width = NULL;
}
