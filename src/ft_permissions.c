
#include "ft_ls.h"

char    *ft_permissions(t_info *info)
{
	char		*modeval;
	mode_t 		perm;
	
	modeval = ft_strnew(9);
	perm = (*info).attrib.st_mode;
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
	return (modeval);
}
