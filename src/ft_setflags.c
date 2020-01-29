/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:21:22 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/27 17:54:34 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_illegaloption(char ill, char *available)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(ill, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-", 2);
	ft_putstr_fd(available, 2);
	ft_putendl_fd("] [file ...]", 2);
	return (-1);
}

static void	ft_nullifyflags(t_flags *flags)
{
	flags->all = 0;
	flags->color = 0;
	flags->ell = 0;
	flags->numerically = 0;
	flags->recursively = 0;
	flags->reverse = 0;
	flags->single = 0;
	flags->size = 0;
	flags->time = 0;
	flags->group_only = 0;
	flags->in_line = 0;
}

static void	ft_setcurrentflag_parttwo(char fl, t_flags *flags)
{
	if (fl == 'n' || fl == 'g')
	{
		if (fl == 'n')
			flags->numerically = 1;
		else if (fl == 'g')
			flags->group_only = 1;
		flags->ell = 1;
		flags->in_line = 0;
	}
	else if (fl == '1')
	{
		flags->in_line = 1;
		flags->ell = 0;
	}
}

static void	ft_setcurrentflag_partone(char fl, t_flags *flags)
{
	if (fl == 'R')
		flags->recursively = 1;
	else if (fl == 'a')
		flags->all = 1;
	else if (fl == 'l')
	{
		flags->ell = 1;
		flags->in_line = 0;
	}
	else if (fl == 'r')
		flags->reverse = 1;
	else if (fl == 't')
		flags->time = 1;
	else if (fl == 'S')
		flags->size = 1;
	else if (fl == 'G')
		flags->color = 1;
	else
		ft_setcurrentflag_parttwo(fl, flags);
}

int			ft_setflags(int argc, char **argv, t_flags *flags)
{
	char	*available;
	char	*fl;
	int		i;
	int		j;

	available = "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";
	ft_nullifyflags(flags);
	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] != '-' || !ft_strcmp(argv[i], "-"))
			return (i);
		else if (!ft_strcmp(argv[i], "--"))
			return (i + 1);
		while (argv[i][j])
		{
			if (!(fl = ft_strchr(available, argv[i][j])))
				return (ft_illegaloption(argv[i][j], available));
			ft_setcurrentflag_partone(*fl, flags);
			j++;
		}
		i++;
	}
	return (i);
}
