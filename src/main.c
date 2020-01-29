/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:21:49 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/27 19:48:07 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		lstprint_errors(t_list *lst)
{
	char	*str;

	str = lst->content;
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(2), 2);
}

static void		ft_printall(t_all *all, t_lsflags *flags)
{
	t_list	*point;
	size_t	count;
	size_t	size;

	ft_lstiter(all->errors, &lstprint_errors);
	flags->single = 1;
	ft_printfiles(all->singles, flags);
	flags->single = 0;
	count = 0;
	size = ft_lstlen(all->dirs);
	point = all->dirs;
	while (point)
	{
		if (count == 0 && ((!all->singles && size != 1) || (all->errors && !all->singles)))
			ft_printf("%s:\n", point->content);
		else if (all->errors || all->singles || (count < size && size != 1))
			ft_printf("\n%s:\n", point->content);
		ft_ls(point->content, flags);
		errno = 0;
		point = point->next;
		count++;
	}
	ft_lstdel(&all->errors, lstdel_string);
	ft_lstdel(&all->singles, lstdel_struct);
	ft_lstdel(&all->dirs, lstdel_string);
}

int				main(int argc, char **argv)
{
	t_all	all;
	t_lsflags	flags;
	int		i;

	all.errors = NULL;
	all.singles = NULL;
	all.dirs = NULL;
	if ((i = ft_setflags(argc, argv, &flags)) < 0)
		return (1);
	else if (i < argc)
	{
		while (i < argc)
		{
			ft_create_error_list(argv[i], &all.errors);
			ft_create_file_list(argv[i], &flags, &all.singles);
			ft_create_folder_list(argv[i], &all.dirs);
			i++;
		}
		ft_printall(&all, &flags);
	}
	else
		ft_ls(".", &flags);
	return (0);
}
