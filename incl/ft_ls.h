/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:18:13 by cdarci            #+#    #+#             */
/*   Updated: 2020/02/06 16:11:32 by cdarci           ###   ########.fr       */
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

typedef struct		s_table
{
	int				filesize_colwidth;
	int				group_colwidth;
	int				links_colwidth;
	int				user_colwidth;
	blkcnt_t		total_blkcntsize;
}					t_table;

typedef struct		s_lsflags
{
	int				all;
	int				color;
	int				ell;
	int				group_only;
	int				in_line;
	int				not_sorted;
	int				numerically;
	int				recursively;
	int				reverse;
	int				single;
	int				size;
	int				slash;
	int				time;
	int				user_only;
	t_table			*talbe_width;
}					t_lsflags;

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
	t_lsflags		*flags;
	uid_t			st_uid;
}					t_aboutfile;

typedef struct		s_allargs
{
	t_list			*dirs;
	t_list			*errors;
	t_list			*singles;
}					t_allargs;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void				ft_ls(char *direct, t_lsflags *flags);

/*
** ----------------------------- ft_ls Functions -------------------------------
*/

blkcnt_t			ft_elltotal(t_list *files);
char				*ft_fullpath(char *curr, char *next);
char				*ft_permissions(t_aboutfile *about);
int					ft_numlen(long long n);
int					ft_setflags(int argc, char **argv, t_lsflags *flags);
t_list				*ft_readdir(char *direct, t_lsflags *flags);
void				ft_ellgroup(int width, gid_t gid, t_lsflags *flags);
void				ft_ellmode(t_aboutfile *about);
void				ft_ellname(t_list *file);
void				ft_elltime(t_aboutfile *about);
void				ft_elluser(int width, uid_t uid, t_lsflags *flags);
void				ft_longformat(t_list *files);
void				ft_printfiles(t_list *files);
void				ft_statcpy(t_aboutfile *about, t_lsflags *flags, \
		struct stat *st);
void				ft_printfilename(t_list *file);

void				lstdel_func(void *content, size_t content_size);
int					lstsort_func(t_list *current, t_list *next);
void				ft_addto_errorslist(char *argv, t_list **errlst);
void				ft_addto_fileslist(char *argv, t_lsflags *flags, \
		t_list **sinlst);
void				ft_addto_dirslist(char *argv, t_lsflags *flags, \
		t_list **dirs);

#endif
