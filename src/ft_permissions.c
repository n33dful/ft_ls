
#include "ft_ls.h"

char    *ft_permissions(t_list *file)
{
	struct stat	st;
	char		*modeval;
	mode_t		perm;
	t_info		*info;

	info = (t_info *)file->content;
    modeval = ft_strnew(9);
    if ((*info).dirent->d_type == 10 && (*info).full_path)
        lstat((*info).full_path, &st);
    else if ((*info).dirent->d_type == 10 && !(*info).full_path)
        lstat((*info).dirent->d_name, &st);
    else if ((*info).full_path)
        stat((*info).full_path, &st);
    else
        stat((*info).dirent->d_name, &st);
    perm = st.st_mode;
    modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
    modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
    modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
    modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
    modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
    modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
    modeval[6] = (perm & S_IROTH) ? 'r' : '-';
    modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
    modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
    modeval[9] = '\0';
    return modeval; 
}
