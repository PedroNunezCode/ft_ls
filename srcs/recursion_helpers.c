/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion-helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:30:14 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/13 19:37:08 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*create_path(char *path, char *new_path)
{
	char *info;

	info = malloc(sizeof(char) * (strlen(path) + strlen(new_path) + 2));
	info = ft_strcpy(info, path);
	ft_strcat(info, "/");
	ft_strcat(info, new_path);
	return (info);
}

void		sps(char *name, t_flags *flags, char *path)
{
	struct stat		*filestats;
	struct passwd	*passwd;
	struct group	*grp;
	char			*tmp;

	filestats = malloc(sizeof(struct stat));
	lstat(path, filestats);
	passwd = getpwuid(filestats->st_uid);
	grp = getgrgid(passwd->pw_gid);
	if (flags->l == 1)
	{
		print_perms(filestats);
		tmp = ctime(&filestats->st_mtime);
		tmp[16] = '\0';
		if ((S_ISCHR(filestats->st_mode) || S_ISBLK(filestats->st_mode)) &&
				print_chr_blk(filestats, passwd, grp))
			continue_chr_print(filestats, tmp, name);
		else if (non_chr_blk(filestats, passwd, grp))
			continue_nonchr_print(tmp, name);
		ft_putstr("\n");
	}
	else
		ft_putendl(name);
	free(filestats);
}

void		print_l_num(char **folders, t_flags *flags, char *path, int i)
{
	char *res;

	res = ft_itoa(totaldirs(folders, flags, path, i));
	ft_putstr("total ");
	ft_putendl(res);
	free(res);
}

void		init_perms(char **folders, char *path, t_flags *flags)
{
	char	*tmp;
	int		i;

	i = -1;
	while (folders[++i])
	{
		tmp = create_path(path, folders[i]);
		if (folders[i][0] != '.' && flags->a != 1)
			sps(folders[i], flags, tmp);
		else if (flags->a == 1)
			sps(folders[i], flags, tmp);
		free(tmp);
	}
	ft_putstr("\n");
}
