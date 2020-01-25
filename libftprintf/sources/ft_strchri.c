
#include "ft_printf.h"

int		ft_strchri(char *s, int c, int i)
{
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

int		ft_strchri_lu(char *s, int c, int i)
{
	i = -1;
	while (s[++i])
		if (s[i] == c || s[i] == c + 32)
			return (i);
	return (-1);
}
