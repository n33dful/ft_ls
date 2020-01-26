/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:18:35 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:18:37 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printfiles(t_list *files, t_flags *flags)
{
	t_about			*about;

	if (flags->ell)
		ft_longformat(files, flags);
	else
	{
		while (files)
		{
			about = files->content;
			if (flags->color && (about->st_mode & S_IFDIR) == 0040000)
				ft_printf("\033[34m%s\033[0m\n", about->d_name);
			else if (flags->color && (about->st_mode & S_IFLNK) == 0120000)
				ft_printf("\033[35m%s\033[0m\n", about->d_name);
			else if (flags->color && (about->st_mode & S_IXUSR) == 0000100)
				ft_printf("\033[31m%s\033[0m\n", about->d_name);
			else
				ft_printf("%s\n", about->d_name);
			files = files->next;
		}
	}
}
