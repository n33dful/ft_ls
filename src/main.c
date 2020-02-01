/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:21:49 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/31 11:53:09 by cdarci           ###   ########.fr       */
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

static void		ft_printall(t_allargs *args, t_lsflags *flags)
{
	t_list	*point;
	size_t	count;
	size_t	size;

	ft_lstiter(args->errors, lstprint_errors);
	flags->single = 1;
	ft_printfiles(args->singles);
	flags->single = 0;
	count = 0;
	size = ft_lstlen(args->dirs);
	point = args->dirs;
	while (point)
	{
		if (count == 0 && ((!args->singles && size != 1) || (args->errors && !args->singles)))
			ft_printf("%s:\n", point->content);
		else if (args->errors || args->singles || (count < size && size != 1))
			ft_printf("\n%s:\n", point->content);
		ft_ls(point->content, flags);
		errno = 0;
		point = point->next;
		count++;
	}
	ft_lstdel(&args->errors, lstdel_func);
	ft_lstdel(&args->singles, lstdel_func);
	ft_lstdel(&args->dirs, lstdel_func);
}

int				main(int argc, char **argv)
{
	t_allargs	args;
	t_lsflags	flags;
	int			i;

	args.errors = NULL;
	args.singles = NULL;
	args.dirs = NULL;
	if ((i = ft_setflags(argc, argv, &flags)) < 0)
		return (1);
	else if (i < argc)
	{
		while (i < argc)
		{
			ft_addto_errorslist(argv[i], &args.errors);
			ft_addto_fileslist(argv[i], &flags, &args.singles);
			ft_addto_dirslist(argv[i], &flags, &args.dirs);
			i++;
		}
		ft_printall(&args, &flags);
	}
	else
		ft_ls(".", &flags);
	return (0);
}
