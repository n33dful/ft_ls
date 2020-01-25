
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
        ft_putchar('@');
    else if (acl != NULL)
        ft_putchar('+');
    else
        ft_putchar(' ');
}

void        ft_ellmode(t_about *about)
{
	if ((about->st_mode & S_IFDIR) == 0040000)
		ft_putchar('d');
	else if ((about->st_mode & S_IFLNK) == 0120000)
		ft_putchar('l');
    else
		ft_putchar('-');
	ft_putchar((about->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((about->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((about->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((about->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((about->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((about->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((about->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((about->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((about->st_mode & S_IXOTH) ? 'x' : '-');
	ft_printacl(about);
	ft_putchar(' ');
}
