/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:15:17 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/13 19:16:13 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** This function simply handles printing an error message. If the flags aren't
** a valid one the program will print an error and quit the process.
*/

int		valid_flag(char flag)
{
	if (flag == 'a' || flag == 'l' || flag == 'R' || flag == 'r' || flag == 't')
		return (1);
	else
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(flag);
		ft_putstr("\n");
		ft_putstr("usage: ls [-lRart] [ File ...]\n");
		exit(0);
	}
}

void	access_error(char *directory)
{
	ft_putstr("ls: ");
	ft_putstr(directory);
	ft_putendl(": No such file or directory");
	exit(1);
}

void	print_path(char *path)
{
	ft_putstr(path);
	ft_putendl(":");
}
