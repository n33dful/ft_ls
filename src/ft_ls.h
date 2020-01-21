
#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_info
{
	struct dirent	*dirent;
    struct stat		attrib;
}					t_info;

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
void				ft_strdel(char **as);

/*
** ft_ls functions
*/
int					ft_setflags(int argc, char **argv, t_flags *flags);
void				ft_ls(char *dir_name, t_flags *flags);
void				ft_printfiles(t_list *files);
void				ft_readdir(DIR *dir, t_flags *flags, t_list **files, t_list **queue);
void				ft_sortfiles(t_flags *flags, t_list **files, t_list **queue);

#endif
