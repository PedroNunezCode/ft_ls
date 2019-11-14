/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:18:11 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/13 19:19:19 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_perms(struct stat *filestats)
{
	if (S_ISDIR(filestats->st_mode))
		ft_putstr("d");
	else if (S_ISLNK(filestats->st_mode))
		ft_putstr("l");
	else if (S_ISCHR(filestats->st_mode))
		ft_putstr("c");
	else if (S_ISBLK(filestats->st_mode))
		ft_putstr("b");
	else if (S_ISFIFO(filestats->st_mode))
		ft_putstr("p");
	else
		ft_putstr("-");
	ft_putstr((filestats->st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((filestats->st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((filestats->st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((filestats->st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((filestats->st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((filestats->st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((filestats->st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((filestats->st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((filestats->st_mode & S_IXOTH) ? "x" : "-");
}

int			print_chr_blk(struct stat *filestats, struct passwd *psswd,
				struct group *grp)
{
	ft_putstr("  ");
	ft_putnbr(filestats->st_nlink);
	ft_putstr(" ");
	ft_putstr(psswd->pw_name);
	ft_putstr("\t");
	ft_putstr(grp->gr_name);
	ft_putnbr(4);
	ft_putstr(",");
	return (1);
}

int			non_chr_blk(struct stat *filestats, struct passwd *psswd,
				struct group *grp)
{
	char *fix;

	fix = ft_itoa(filestats->st_size);
	ft_putstr(" ");
	ft_putnbr(filestats->st_nlink);
	ft_putstr("\t");
	ft_putstr(psswd->pw_name);
	ft_putstr(" ");
	ft_putstr(grp->gr_name);
	ft_putstr(" ");
	if (ft_strlen(fix) <= 1)
	{
		ft_putstr("   ");
		ft_putstr(fix);
	}
	else
		ft_putnbr(filestats->st_size);
	free(fix);
	return (1);
}

void		continue_chr_print(struct stat *filestats, char *tmp, char *name)
{
	ft_putnbr(major(filestats->st_rdev));
	ft_putnbr(4);
	ft_putnbr(minor(filestats->st_rdev));
	ft_putstr(tmp + 4);
	ft_putstr(name);
}

void		continue_nonchr_print(char *tmp, char *name)
{
	ft_putstr("\t");
	ft_putstr(tmp + 4);
	ft_putstr("\t");
	ft_putstr(name);
}
