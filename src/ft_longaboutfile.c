/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longaboutfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:16:44 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:16:47 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_elluser(int width, uid_t uid, t_lsflags *flags)
{
	struct passwd *pass;

	pass = getpwuid(uid);
	if (pass->pw_name && !flags->numerically)
		ft_printf("%-*s", width, pass->pw_name);
	else
		ft_printf("%-*d", width, uid);
	ft_printf("  ");
}

void	ft_ellgroup(int width, gid_t gid, t_lsflags *flags)
{
	struct group *gr;

	gr = getgrgid(gid);
	if (gr->gr_name && !flags->numerically)
		ft_printf("%-*s", width, gr->gr_name);
	else
		ft_printf("%-*d", width, gid);
	ft_printf("  ");
}

void	ft_elltime(t_aboutfile *about)
{
	char		*strtime;

	strtime = ctime(&(about->m_time));
	strtime[ft_strlen(strtime) - 1] = '\0';
	ft_printf("%.4s", strtime + 4);
	ft_printf("%.3s", strtime + 8);
	if (time(NULL) - about->m_time > 15811200)
		ft_printf("%5.4s", strtime + 20);
	else if (time(NULL) - about->m_time < 0)
		ft_printf(" %s", ft_strrchr(strtime, ' ') + 1);
	else
		ft_printf("%.5s", strtime + 11);
	ft_printf(" ");
}

void	ft_ellname(t_aboutfile *about, t_lsflags *flags)
{
	char	buf[1024];
	char	*full;
	ssize_t	rs;

	full = about->full_path;
	rs = readlink(full ? full : about->d_name, buf, 1024);
	buf[rs] = '\0';
	if (rs && flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
		ft_printf("\033[35m%s\033[0m -> %s", about->d_name, buf);
	else if (flags->color && (about->st_mode & S_IFMT) == S_IFDIR)
		ft_printf("\033[34m%s\033[0m", about->d_name);
	else if (flags->color && (about->st_mode & S_IFMT) == S_IXUSR)
		ft_printf("\033[31m%s\033[0m", about->d_name);
	else if (rs && !flags->color && (about->st_mode & S_IFMT) == S_IFLNK)
		ft_printf("%s -> %s", about->d_name, buf);
	else
		ft_printf("%s", about->d_name);
	if (flags->slash && (about->st_mode & S_IFMT) == S_IFDIR)
		ft_printf("/");
	ft_printf("\n");
}
