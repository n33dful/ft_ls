
#include "ft_ls.h"

static void	ft_printacl(t_about *about)
{
    acl_t		acl;
    acl_entry_t	dummy;
    ssize_t		xattr;
    char		chr;
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
        chr = '@';
    else if (acl != NULL)
        chr = '+';
    else
        chr = ' ';
    printf("%c", chr);
}

void        ft_ellmode(t_about *about)
{
	if (about->d_type == 4)
		printf("d");
	else if (about->d_type == 10)
		printf("ell");
	else
		printf("-");
	printf("%c", (about->st_mode & S_IRUSR) ? 'r' : '-');
	printf("%c", (about->st_mode & S_IWUSR) ? 'w' : '-');
	printf("%c", (about->st_mode & S_IXUSR) ? 'x' : '-');
	printf("%c", (about->st_mode & S_IRGRP) ? 'r' : '-');
	printf("%c", (about->st_mode & S_IWGRP) ? 'w' : '-');
	printf("%c", (about->st_mode & S_IXGRP) ? 'x' : '-');
	printf("%c", (about->st_mode & S_IROTH) ? 'r' : '-');
	printf("%c", (about->st_mode & S_IWOTH) ? 'w' : '-');
	printf("%c", (about->st_mode & S_IXOTH) ? 'x' : '-');
	ft_printacl(about);
	printf(" ");
}
