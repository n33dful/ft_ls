/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:18:35 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:18:37 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned short	ft_finedeverycolumnwidth(t_list *files)
{
	unsigned short	col_w;
	unsigned short	tmp;
	t_aboutfile		*about;

	col_w = 0;
	while (files)
	{
		about = files->content;
		tmp = ft_strlen(about->d_name);
		if (tmp > col_w)
			col_w = tmp;
		files = files->next;
	}
	return (col_w / 8 * 8 + 8);
}

static void	ft_printeverynlist(t_list *files, unsigned short width, unsigned short amount_ofelems)
{
	t_aboutfile		*about;
	unsigned short	lstlen;
	unsigned short	count;
	unsigned short	i;

	about = files->content;
	ft_printf("%-*s", width, about->d_name);
	files = files->next;
	i = 1;
	count = 1;
	lstlen = ft_lstlen(files);
	while (i <= lstlen && files && count < amount_ofelems)
	{
		if (((i) % (amount_ofelems + 1)) == 0)
		{
			about = files->content;
			ft_printf("%-*s", width, about->d_name);
			count++;
		}
		files = files->next;
		i++;
	}
}

static void	ft_tableview(t_list *files, t_lsflags *flags)
{
	struct winsize	ws;
	t_aboutfile		*about;
	unsigned short	columns;
	unsigned short	col_w;
	unsigned short	lines;
	unsigned short	i;

	i = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	col_w = ft_finedeverycolumnwidth(files);
	columns = ws.ws_col / col_w;
	if (columns == 0)
		columns = 1;
	if ((unsigned short)ft_lstlen(files) % columns == 0)
		lines = (unsigned short)ft_lstlen(files) / columns;
	else
		lines = (unsigned short)ft_lstlen(files) / columns + 1;
	if (lines == 1)
	{
		while (files)
		{
			about = files->content;
			if (flags->color && (about->st_mode & S_IFMT) == S_IFDIR)
				ft_printf("\033[34m%-*s\033[0m", col_w, about->d_name);
			else if (flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
				ft_printf("\033[35m%-*s\033[0m", col_w, about->d_name);
			else if (flags->color && (about->st_mode & S_IXUSR) == 0000100)
				ft_printf("\033[31m%-*s\033[0m", col_w, about->d_name);
			else
				ft_printf("%-*s", col_w, about->d_name);
			if (flags->slash && (about->st_mode & S_IFMT) == S_IFDIR)
				ft_printf("/");
			files = files->next;
		}
		ft_printf("\n");
	}
	else if (columns == 1)
	{
		while (files)
		{
			about = files->content;
			if (flags->color && (about->st_mode & S_IFMT) == S_IFDIR)
				ft_printf("\033[34m%s\033[0m", about->d_name);
			else if (flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
				ft_printf("\033[35m%s\033[0m", about->d_name);
			else if (flags->color && (about->st_mode & S_IXUSR) == 0000100)
				ft_printf("\033[31m%s\033[0m", about->d_name);
			else
				ft_printf("%s", about->d_name);
			if (flags->slash && (about->st_mode & S_IFMT) == S_IFDIR)
				ft_printf("/");
			ft_printf("\n");
			files = files->next;
		}
	}
	else
	{
		if ((unsigned short)ft_lstlen(files) % columns == 0)
		{
			while(i < lines)
			{
				about = files->content;
				ft_printeverynlist(files, col_w, lines);
				ft_printf("\n");
				files = files->next;
				i++;
			}
		}
		else
		{
			while(i < lines)
			{
				about = files->content;
				ft_printeverynlist(files, col_w, lines - 1);
				ft_printf("\n");
				files = files->next;
				i++;
			}
		}
	}
}

void		ft_printfiles(t_list *files, t_lsflags *flags)
{
	t_aboutfile	*about;

	if (flags->ell)
		ft_longformat(files, flags);
	else if (flags->in_line)
	{
		while (files)
		{
			about = files->content;
			if (flags->color && (about->st_mode & S_IFMT) == S_IFDIR)
				ft_printf("\033[34m%s\033[0m", about->d_name);
			else if (flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
				ft_printf("\033[35m%s\033[0m", about->d_name);
			else if (flags->color && (about->st_mode & S_IXUSR) == 0000100)
				ft_printf("\033[31m%s\033[0m", about->d_name);
			else
				ft_printf("%s", about->d_name);
			if (flags->slash && (about->st_mode & S_IFMT) == S_IFDIR)
				ft_printf("/");
			ft_printf("\n");
			files = files->next;
		}
	}
	else
		ft_tableview(files, flags);
}
