
#include "ft_ls.h"

void	*ft_memerror(t_list **files, DIR *dir)
{
	errno = 12;
	ft_lstdel(files, del);
	closedir(dir);
	return (NULL);
}
