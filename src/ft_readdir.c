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

static int	ft_setfullpath(struct dirent *dirent, char *direct, \
t_aboutfile *about)
{
	if (ft_strcmp(direct, "."))
	{
		if (!(about->full_path = ft_fullpath(direct, dirent->d_name)))
			return (0);
	}
	else
		about->full_path = NULL;
	return (1);
}

static void	*ft_memerror(t_list **files, DIR *dir)
{
	ft_lstdel(files, lstdel_struct);
	closedir(dir);
	return (NULL);
}

static int	ft_setdirent(struct dirent *dirent, t_aboutfile *about)
{
	if (!(about->d_name = ft_strdup(dirent->d_name)))
		return (0);
	return (1);
}

static int	ft_setstat(t_lsflags *flags, t_aboutfile *about)
{
	struct stat	st;

	if ((lstat(about->full_path ? \
about->full_path : about->d_name, &st)) != 0)
		return (0);
	about->st_gid = st.st_gid;
	about->st_mode = st.st_mode;
	about->st_nlink = st.st_nlink;
	about->st_uid = st.st_uid;
	about->c_time = st.st_ctimespec.tv_sec;
	about->m_time = st.st_mtimespec.tv_sec;
	about->st_size = st.st_size;
	about->st_blocks = st.st_blocks;
	about->flags = flags;
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
		if (!ft_setfullpath(dirent, direct, &about))
			return (ft_memerror(&files, dir));
		if (!ft_setdirent(dirent, &about))
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
