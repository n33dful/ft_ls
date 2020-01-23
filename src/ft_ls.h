
#ifndef FT_LS_H
# define FT_LS_H

# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <uuid/uuid.h>

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
	__uint8_t		d_type;
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
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
}					t_flags;

/*
** libft functions
*/
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstmove(t_list **alst, void (*del)(void *, size_t));
void				ft_lstsort(t_list **list, int (*func)(t_list *, t_list *));
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_lstlen(t_list *list);
void				ft_putendl_fd(char const *s, int fd);

/*
** ft_ls functions
*/
int					ft_setflags(int argc, char **argv, t_flags *flags);
void				ft_ls(char *direct, t_flags *flags);
t_list				*ft_readdir(char *direct, t_flags *flags);
void				ft_sortfiles(t_list **files, t_flags *flags);
void				ft_printfiles(t_list *files, t_flags *flags);
char    			*ft_permissions(t_about *about);
char				*ft_fullpath(char *currFolder, char *nextFolder);

#endif
