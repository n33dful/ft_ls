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

//unsigned short	ft_finedeverycolumnwidth(t_list *files)
//{
//	unsigned short	col_w;
//	unsigned short	tmp;
//	t_aboutfile		*about;
//
//	col_w = 0;
//	while (files)
//	{
//		about = files->content;
//		tmp = ft_strlen(about->d_name);
//		if (tmp > col_w)
//			col_w = tmp;
//		files = files->next;
//	}
//	return (col_w / 8 * 8 + 8);
//}
//
//static void	ft_printeverynlist(t_list *files, unsigned short width, unsigned short amount_ofelems)
//{
//	t_aboutfile		*about;
//	unsigned short	lstlen;
//	unsigned short	count;
//	unsigned short	i;
//
//	about = files->content;
//	ft_printf("%-*s", width, about->d_name);
//	files = files->next;
//	i = 1;
//	count = 1;
//	lstlen = ft_lstlen(files);
//	while (i <= lstlen && files && count < amount_ofelems)
//	{
//		if (((i) % (amount_ofelems + 1)) == 0)
//		{
//			about = files->content;
//			ft_printf("%-*s", width, about->d_name);
//			count++;
//		}
//		files = files->next;
//		i++;
//	}
//}
//
//static void	ft_tableview(t_list *files, t_lsflags *flags)
//{
//	struct winsize	ws;
//	t_aboutfile		*about;
//	unsigned short	columns;
//	unsigned short	col_w;
//	unsigned short	lines;
//	unsigned short	i;
//
//	i = 0;
//	ioctl(0, TIOCGWINSZ, &ws);
//	col_w = ft_finedeverycolumnwidth(files);
//	columns = ws.ws_col / col_w;
//	if (columns == 0)
//		columns = 1;
//	if ((unsigned short)ft_lstlen(files) % columns == 0)
//		lines = (unsigned short)ft_lstlen(files) / columns;
//	else
//		lines = (unsigned short)ft_lstlen(files) / columns + 1;
//	if (lines == 1)
//	{
//		while (files)
//		{
//			about = files->content;
//			if (flags->color && (about->st_mode & S_IFMT) == S_IFDIR)
//				ft_printf("\033[34m%-*s\033[0m", col_w, about->d_name);
//			else if (flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
//				ft_printf("\033[35m%-*s\033[0m", col_w, about->d_name);
//			else if (flags->color && (about->st_mode & S_IXUSR) == 0000100)
//				ft_printf("\033[31m%-*s\033[0m", col_w, about->d_name);
//			else
//				ft_printf("%-*s", col_w, about->d_name);
//			if (flags->slash && (about->st_mode & S_IFMT) == S_IFDIR)
//				ft_printf("/");
//			files = files->next;
//		}
//		ft_printf("\n");
//	}
//	else if (columns == 1)
//	{
//		while (files)
//		{
//			about = files->content;
//			if (flags->color && (about->st_mode & S_IFMT) == S_IFDIR)
//				ft_printf("\033[34m%s\033[0m", about->d_name);
//			else if (flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
//				ft_printf("\033[35m%s\033[0m", about->d_name);
//			else if (flags->color && (about->st_mode & S_IXUSR) == 0000100)
//				ft_printf("\033[31m%s\033[0m", about->d_name);
//			else
//				ft_printf("%s", about->d_name);
//			if (flags->slash && (about->st_mode & S_IFMT) == S_IFDIR)
//				ft_printf("/");
//			ft_printf("\n");
//			files = files->next;
//		}
//	}
//	else
//	{
//		if ((unsigned short)ft_lstlen(files) % columns == 0)
//		{
//			while(i < lines)
//			{
//				about = files->content;
//				ft_printeverynlist(files, col_w, lines);
//				ft_printf("\n");
//				files = files->next;
//				i++;
//			}
//		}
//		else
//		{
//			while(i < lines)
//			{
//				about = files->content;
//				ft_printeverynlist(files, col_w, lines - 1);
//				ft_printf("\n");
//				files = files->next;
//				i++;
//			}
//		}
//	}
//}

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
	group = getgrgid(about->st_gid);
	if (group->gr_name && !flags->numerically)
	{
		if ((int)ft_strlen(group->gr_name) > table->group_colwidth)
			table->group_colwidth = ft_strlen(group->gr_name);
	}
	else
	{
		if (ft_numlen(about->st_gid) > table->group_colwidth)
			table->group_colwidth = ft_numlen(about->st_gid);
	}
	passwd = getpwuid(about->st_uid);
	if (passwd->pw_name && !flags->numerically)
	{
		if ((int)ft_strlen(passwd->pw_name) > table->user_colwidth)
			table->user_colwidth = ft_strlen(passwd->pw_name);
	}
	else
	{
		if (ft_numlen(about->st_uid) > table->user_colwidth)
			table->user_colwidth = ft_numlen(about->st_uid);
	}
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
	ft_ellname(about, flags);
}

static void	lstprint_inline(t_list *file)
{
	t_aboutfile	*about;
	t_lsflags	*flags;

	about = file->content;
	flags = about->flags;
	if (flags->color && (about->st_mode & S_IFMT) == S_IFDIR)
		ft_printf("\033[34m%s\033[0m", about->d_name);
	else if (flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
		ft_printf("\033[35m%s\033[0m", about->d_name);
	else if (flags->color && (about->st_mode & S_IXUSR))
		ft_printf("\033[31m%s\033[0m", about->d_name);
	else
		ft_printf("%s", about->d_name);
	if (flags->slash && (about->st_mode & S_IFMT) == S_IFDIR)
		ft_printf("/");
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
	else /*if (flags->in_line)*/
		ft_lstiter(files, lstprint_inline);
	//else
	//	ft_tableview(files, flags);
	flags->talbe_width = NULL;
}
