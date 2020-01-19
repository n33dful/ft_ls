
#ifndef FT_LS_H
# define FT_LS_H

#include <dirent.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include "../libft/libft.h"

typedef struct		s_info
{
	struct dirent	*dirent;
    struct stat		attrib;
}					t_info;

typedef struct		s_flags
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
}					t_flags;


int					ft_setflags(char **argv, t_flags *flags);

void				ft_ls(char *dir_name, t_flags *flags);
void				ft_sortfiles(t_flags *flags, t_list **files, t_list **queue);
void				ft_printfiles(t_list *files);

#endif
