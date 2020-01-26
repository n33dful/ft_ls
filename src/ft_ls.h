
#ifndef FT_LS_H
# define FT_LS_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <uuid/uuid.h>
# include <sys/ttycom.h>

/*
** -------------------------- Colors Definition --------------------------------
*/

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[0m"

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_aboutfile
{
	char			*full_path;
	char			*d_name;
	unsigned char	d_type;
	__darwin_time_t	c_time;
	__darwin_time_t	m_time;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	blkcnt_t		st_blocks;
}					t_about;

typedef struct		s_flags
{
	int				ell;
	int				recursively;
	int				all;
	int				reverse;
	int				time;
	int				size;
	int				single;
	int				color;
}					t_flags;

typedef struct		s_all
{
	t_list			*errors;
	t_list			*singles;
	t_list			*dirs;
	t_list			*denied;
}					t_all;


/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int					ft_printf(const char *format, ...);
void				ft_ls(char *direct, t_flags *flags);

/*
** ------------------------------ Libft Functions ------------------------------
*/
void				ft_lstsort(t_list **list, int (*func)(t_list *, t_list *));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstmove(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
size_t				ft_lstlen(t_list *list);
void				ft_putstr(char const *s);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putchar(char c);
char				*ft_strrchr(const char *s, int c);

/*
** ------------------------------ Sort Functions -------------------------------
*/
int					by_name_asc(t_list *current, t_list *next);
int					by_time_asc(t_list *current, t_list *next);
int					by_size_asc(t_list *current, t_list *next);
int					by_name_desc(t_list *current, t_list *next);
int					by_time_desc(t_list *current, t_list *next);
int					by_size_desc(t_list *current, t_list *next);

/*
** ----------------------------- ft_ls Functions -------------------------------
*/
int					ft_numlen(long long n);
void				ft_ellmode(t_about *about);
void				ft_elltime(t_about *about);
void				ft_ellname(t_about *about, t_flags *flags);
void				ft_longformat(t_list *files, t_flags *flags);
blkcnt_t			ft_elltotal(t_list *files);
void				ft_elluser(int width, uid_t uid);
void				ft_ellgroup(int width, gid_t gid);
char    			*ft_permissions(t_about *about);
void				*ft_memerror(t_list **files, DIR *dir);
void				del(void *content, size_t content_size);
t_list				*ft_readdir(char *direct, t_flags *flags);
void				ft_sortfiles(t_list **files, t_flags *flags);
void				ft_printfiles(t_list *files, t_flags *flags);
char				*ft_fullpath(char *currFolder, char *nextFolder);
int					ft_setflags(int argc, char **argv, t_flags *flags);

#endif
