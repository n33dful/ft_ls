/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:18:02 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/27 20:03:30 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_recursively(char *direct, t_flags *flags, t_list *files)
{
	char	*nextdirect;
	t_about	*about;

	while (files)
	{
		about = files->content;
		if ((about->st_mode & S_IFMT) == S_IFDIR && \
ft_strcmp(about->d_name, ".") && ft_strcmp(about->d_name, ".."))
		{
			nextdirect = ft_fullpath(direct, about->d_name);
			ft_printf("\n%s:\n", nextdirect);
			ft_ls(nextdirect, flags);
			ft_strdel(&nextdirect);
		}
		files = files->next;
	}
}

static void	ft_error(char *direct)
{
	char	*pointer;

	ft_putstr_fd("ls: ", 2);
	pointer = ft_strrchr(direct, '/');
	if (pointer)
		ft_putstr_fd(pointer + 1, 2);
	else
		ft_putstr_fd(direct, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	errno = 0;
}

void		ft_ls(char *direct, t_flags *flags)
{
	t_list	*files;

	errno = 0;
	if (!(files = ft_readdir(direct, flags)) && errno != 0)
		return (ft_error(direct));
	ft_sortfiles(&files, flags);
	ft_printfiles(files, flags);
	if (flags->recursively)
		ft_recursively(direct, flags, files);
	ft_lstdel(&files, lstdel_struct);
}
