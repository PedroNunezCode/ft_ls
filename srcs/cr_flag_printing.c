/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_R_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:21:16 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/13 19:27:19 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	rec_perms(char **fol, char *path, t_flags *flags)
{
	int		i;
	char	*tmp;

	i = 0;
	while (fol[i])
	{
		tmp = create_path(path, fol[i]);
		if (fol[i][0] != '.' && flags->a != 1)
			recursive_directory_print(tmp, flags, 0);
		else if (strcmp(fol[i], ".") != 0 && strcmp(fol[i], "..")
			!= 0 && flags->a == 1)
			recursive_directory_print(tmp, flags, 0);
		free(tmp);
		i++;
	}
}

void	recursive_directory_print(char *path, t_flags *flags, int i)
{
	char	**folders;
	char	**head;
	DIR		*dir_stream;

	dir_stream = opendir(path);
	if (dir_stream == NULL)
		return ;
	print_path(path);
	folders = sorted_folders(dir_stream, flags, 0);
	if (flags->l == 1)
		print_l_num(folders, flags, path, i);
	init_perms(folders, path, flags);
	closedir(dir_stream);
	dir_stream = opendir(path);
	i = 0;
	rec_perms(folders, path, flags);
	closedir(dir_stream);
	head = folders;
	while (*folders)
	{
		free(*folders);
		folders++;
	}
	free(head);
}

void	handle_capital_r_flag(DIR *directory, t_info *program_info)
{
	int i;

	i = 0;
	if (!(directory = opendir(program_info->directories[i])))
		access_error(program_info->directories[i]);
	else
		recursive_directory_print(program_info->directories[i],
				program_info->flag_struct, 0);
	closedir(directory);
}
