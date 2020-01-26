/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ellname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:16:50 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:21:00 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ellname(t_about *about, t_flags *flags)
{
	char	buf[1024];
	char	*full;
	ssize_t	rs;

	full = about->full_path;
	rs = readlink(full ? full : about->d_name, buf, 1024);
	buf[rs] = '\0';
	if (rs && flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
		ft_printf("\033[35m%s\033[0m -> %s", about->d_name, buf);
	else if (rs && !flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
		ft_printf("%s -> %s", about->d_name, buf);
	else if (flags->color && (about->st_mode & S_IFMT) == S_IFDIR)
		ft_printf("\033[34m%s\033[0m", about->d_name);
	else if (flags->color && (about->st_mode & S_IFMT) == S_IXUSR)
		ft_printf("\033[31m%s\033[0m", about->d_name);
	else
		ft_printf("%s", about->d_name);
}
