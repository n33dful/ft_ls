/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:21:11 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/30 19:28:02 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_setdirent(struct dirent *dirent, char *dir, t_aboutfile *about)
{
	if (!(about->d_name = ft_strdup(dirent->d_name)))
		return (0);
	if (ft_strcmp(dir, "."))
	{
		if (!(about->full_path = ft_fullpath(dir, dirent->d_name)))
		{
			ft_strdel(&(about->d_name));
			return (0);
		}
	}
	else
		about->full_path = NULL;
	return (1);
}

static void	*ft_memerror(t_list **files, DIR *dir)
{
	ft_lstdel(files, lstdel_func);
	closedir(dir);
	return (NULL);
}

void		ft_statcpy(t_aboutfile *about, t_lsflags *flags, struct stat *st)
{
	about->st_gid = st->st_gid;
	about->st_mode = st->st_mode;
	about->st_nlink = st->st_nlink;
	about->st_uid = st->st_uid;
	about->c_time = st->st_ctimespec.tv_sec;
	about->m_time = st->st_mtimespec.tv_sec;
	about->st_size = st->st_size;
	about->st_blocks = st->st_blocks;
	about->flags = flags;
}

static int	ft_setstat(t_lsflags *flags, t_aboutfile *about)
{
	struct stat	st;

	if ((lstat(about->full_path ? \
about->full_path : about->d_name, &st)) != 0)
		return (0);
	ft_statcpy(about, flags, &st);
	return (1);
}

t_list		*ft_readdir(char *direct, t_lsflags *flags)
{
	DIR				*dir;
	t_list			*files;
	t_list			*new;
	t_aboutfile		about;
	struct dirent	*dirent;

	files = NULL;
	if (!(dir = opendir(direct)))
		return (NULL);
	while ((dirent = readdir(dir)) != NULL)
	{
		if (dirent->d_name[0] == '.' && !flags->all)
			continue ;
		if (!ft_setdirent(dirent, direct, &about))
			return (ft_memerror(&files, dir));
		if (!ft_setstat(flags, &about))
			return (ft_memerror(&files, dir));
		if (!(new = ft_lstnew(&about, sizeof(t_aboutfile))))
			return (ft_memerror(&files, dir));
		ft_lstadd_back(&files, new);
	}
	closedir(dir);
	return (files);
}
