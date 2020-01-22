#include "ft_ls.h"

char	*ft_nextFolder(char *currFolder, char *nextFolder)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin("/", nextFolder);
	res = ft_strjoin(currFolder, tmp);
	ft_strdel(&tmp);
	return (res);
}
