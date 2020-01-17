
#ifndef FT_LS_H
# define FT_LS_H

#include <dirent.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "../libft/libft.h"

typedef struct		s_queue
{
	char			*d_name;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_flags
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
}					t_flags;

t_queue				*create_queue_elem(char *d_name);
int					add_to_queue(t_queue **queue, t_queue *elem);
void				delete_queue(t_queue *queue);
char				*next_elem_in_queue(t_queue **queue);
t_flags				*set_flags(char **argv);

void				ft_ls(char *dirname, t_flags *flags);
void				option_R(t_queue *queue, t_flags *flags);

#endif
