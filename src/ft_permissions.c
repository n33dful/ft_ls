
#include "ft_ls.h"

char    *ft_permissions(t_about *about)
{
	char		*permissions;

    if (!(permissions = ft_strnew(9)))
        return (NULL);
    permissions[0] = (about->st_mode & S_IRUSR) ? 'r' : '-';
    permissions[1] = (about->st_mode & S_IWUSR) ? 'w' : '-';
    permissions[2] = (about->st_mode & S_IXUSR) ? 'x' : '-';
    permissions[3] = (about->st_mode & S_IRGRP) ? 'r' : '-';
    permissions[4] = (about->st_mode & S_IWGRP) ? 'w' : '-';
    permissions[5] = (about->st_mode & S_IXGRP) ? 'x' : '-';
    permissions[6] = (about->st_mode & S_IROTH) ? 'r' : '-';
    permissions[7] = (about->st_mode & S_IWOTH) ? 'w' : '-';
    permissions[8] = (about->st_mode & S_IXOTH) ? 'x' : '-';
    permissions[9] = '\0';
    return (permissions);
}
