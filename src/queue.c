
#include "ft_ls.h"

t_queue	*create_queue_elem(char *d_name)
{
	t_queue	*elem;

	if (!(elem = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	if (!(elem->d_name = ft_strdup(d_name)))
	{
		free(elem);
		return (NULL);
	}
	elem->next = NULL;
	return (elem);
}

int		add_to_queue(t_queue **queue, t_queue *elem)
{
	t_queue	*pointer;

	pointer = (*queue);
	if (!elem)
	{
		delete_queue((*queue));
		return (0);
	}
	if (!pointer)
		(*queue) = elem;
	else
	{
		while (pointer->next)
			pointer = pointer->next;
		pointer->next = elem;
	}
	return (1);
}

void	delete_queue(t_queue *queue)
{
	t_queue	*current;

	while (queue)
	{
		current = queue;
		queue = queue->next;
		ft_strdel(&(current->d_name));
		free(current);
	}
}

char	*next_elem_in_queue(t_queue **queue)
{
	t_queue	*current;
	char	*d_name;

	d_name = NULL;
	current = (*queue);
	if (current)
	{
		(*queue) = (*queue)->next;
		current->next = NULL;
		d_name = current->d_name;
		free(current);
	}
	return (d_name);
}
