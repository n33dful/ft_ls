/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:18:13 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/27 13:37:18 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../library/ft_printf/incl/libftprintf.h"
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <sys/acl.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <sys/ttycom.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <uuid/uuid.h>

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct		s_aboutfile
{
	__darwin_time_t	c_time;
	__darwin_time_t	m_time;
	blkcnt_t		st_blocks;
	char			*d_name;
	char			*full_path;
	gid_t			st_gid;
	mode_t			st_mode;
	nlink_t			st_nlink;
	off_t			st_size;
	uid_t			st_uid;
}					t_about;

typedef struct		s_flags
{
	int				all;
	int				color;
	int				ell;
	int				numerically;
	int				recursively;
	int				reverse;
	int				single;
	int				size;
	int				time;
}					t_flags;

typedef struct		s_all
{
	t_list			*dirs;
	t_list			*errors;
	t_list			*singles;
}					t_all;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void				ft_ls(char *direct, t_flags *flags);

/*
** ------------------------------ Sort Functions -------------------------------
*/

int					by_name_asc(t_list *current, t_list *next);
int					by_name_desc(t_list *current, t_list *next);
int					by_size_asc(t_list *current, t_list *next);
int					by_size_desc(t_list *current, t_list *next);
int					by_time_asc(t_list *current, t_list *next);
int					by_time_desc(t_list *current, t_list *next);

/*
** ----------------------------- ft_ls Functions -------------------------------
*/

blkcnt_t			ft_elltotal(t_list *files);
char				*ft_fullpath(char *curr, char *next);
char				*ft_permissions(t_about *about);
int					ft_numlen(long long n);
int					ft_setflags(int argc, char **argv, t_flags *flags);
t_list				*ft_readdir(char *direct, t_flags *flags);
void				lstdel_struct(void *content, size_t content_size);
void				ft_ellgroup(int width, gid_t gid, t_flags *flags);
void				ft_ellmode(t_about *about);
void				ft_ellname(t_about *about, t_flags *flags);
void				ft_elltime(t_about *about);
void				ft_elluser(int width, uid_t uid, t_flags *flags);
void				ft_longformat(t_list *files, t_flags *flags);
void				ft_printfiles(t_list *files, t_flags *flags);
void				ft_sortfiles(t_list **files, t_flags *flags);
void				lstdel_string(void *content, size_t content_size);

#endif
