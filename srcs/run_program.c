/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:38:20 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/13 19:40:25 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	simple_output(char *path, t_flags *flags, int i)
{
	DIR		*dir;
	char	**fol;
	char	*tmp;
	int		result;

	result = 0;
	dir = opendir(path);
	fol = sorted_folders(dir, flags, 0);
	if (flags->l == 1)
	{
		ft_putstr("total ");
		tmp = ft_itoa(totaldirs(fol, flags, path, result));
		ft_putendl(tmp);
		free(tmp);
	}
	while (fol[++i])
	{
		tmp = create_path(path, fol[i]);
		(fol[i][0] != '.' && flags->a != 1) ? sps(fol[i], flags, tmp) : 0;
		(flags->a == 1) ? sps(fol[i], flags, tmp) : 0;
		free(fol[i]);
		free(tmp);
	}
	closedir(dir);
	free(fol);
}

void	start_output(DIR *directory_stream, t_info *program_info, int i)
{
	if (!(directory_stream = opendir(program_info->directories[i])))
		access_error(program_info->directories[i]);
	else if (program_info->num_of_dirs > 1)
	{
		ft_putendl(program_info->directories[i]);
		simple_output(program_info->directories[i],
				program_info->flag_struct, -1);
	}
	else
		simple_output(program_info->directories[i],
				program_info->flag_struct, -1);
	closedir(directory_stream);
}

/*
**	This function will handle running the program after all
**	the structs have been setup.
*/

void	process_directories(t_info *program_info)
{
	DIR *directory;
	int i;

	directory = NULL;
	i = -1;
	while (++i < program_info->num_of_dirs)
	{
		if (program_info->flag_struct->cr == 1)
			handle_capital_r_flag(directory, program_info);
		else
			start_output(directory, program_info, i);
	}
	i = 0;
	while (program_info->directories[i])
	{
		free(program_info->directories[i]);
		i++;
	}
	free(program_info->directories);
	free(program_info->flag_struct);
}
