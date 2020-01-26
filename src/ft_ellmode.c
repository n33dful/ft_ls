/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ellmode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:23:24 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:23:27 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_printacl(t_about *about)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;
	char		*filename;

	filename = about->full_path ? about->full_path : about->d_name;
	acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		ft_printf("@");
	else if (acl != NULL)
		ft_printf("+");
	else
		ft_printf(" ");
}

void		ft_ellmode(t_about *about)
{
	if ((about->st_mode & S_IFMT) == S_IFBLK)
		ft_printf("b");
	else if ((about->st_mode & S_IFMT) == S_IFCHR)
		ft_printf("c");
	else if ((about->st_mode & S_IFMT) == S_IFDIR)
		ft_printf("d");
	else if ((about->st_mode & S_IFMT) == S_IFLNK)
		ft_printf("l");
	else if ((about->st_mode & S_IFMT) == S_IFSOCK)
		ft_printf("s");
	else if ((about->st_mode & S_IFMT) == S_IFIFO)
		ft_printf("p");
	else if ((about->st_mode & S_IFMT) == S_IFREG)
		ft_printf("-");
	ft_printf("%c", (about->st_mode & S_IRUSR) ? 'r' : '-');
	ft_printf("%c", (about->st_mode & S_IWUSR) ? 'w' : '-');
	ft_printf("%c", (about->st_mode & S_IXUSR) ? 'x' : '-');
	ft_printf("%c", (about->st_mode & S_IRGRP) ? 'r' : '-');
	ft_printf("%c", (about->st_mode & S_IWGRP) ? 'w' : '-');
	ft_printf("%c", (about->st_mode & S_IXGRP) ? 'x' : '-');
	ft_printf("%c", (about->st_mode & S_IROTH) ? 'r' : '-');
	ft_printf("%c", (about->st_mode & S_IWOTH) ? 'w' : '-');
	ft_printf("%c", (about->st_mode & S_IXOTH) ? 'x' : '-');
	ft_printacl(about);
	ft_printf(" ");
}
