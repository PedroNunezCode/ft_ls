/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:01:09 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/13 19:08:33 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**	This function handles setting up the flag stucture then cleaning up
**	garbage memory.
*/

void	setup_flag_structure(t_info *program_info)
{
	int		i;

	i = -1;
	program_info->flag_struct = malloc(sizeof(t_flags));
	program_info->flag_struct->cr = 0;
	program_info->flag_struct->l = 0;
	program_info->flag_struct->a = 0;
	program_info->flag_struct->r = 0;
	program_info->flag_struct->t = 0;
	while (program_info->num_of_flags > ++i)
	{
		if (program_info->string_flags[i] == 'R')
			program_info->flag_struct->cr = 1;
		else if (program_info->string_flags[i] == 'l')
			program_info->flag_struct->l = 1;
		else if (program_info->string_flags[i] == 'a')
			program_info->flag_struct->a = 1;
		else if (program_info->string_flags[i] == 'r')
			program_info->flag_struct->r = 1;
		else if (program_info->string_flags[i] == 't')
			program_info->flag_struct->t = 1;
	}
	free(program_info->string_flags);
}

/*
**  This function handles saving the flags into the string_flags array.
**  this will be used to create the flag structure. Thus allowing me to
** easily check the flags down the road.
*/

void	store_string_flags(char *av[], t_info *program_info)
{
	int i;
	int j;
	int k;

	i = 0;
	j = -1;
	program_info->string_flags = malloc((sizeof(char)) *
			(program_info->num_of_flags));
	while (av[++i])
	{
		if (av[i][0] == '-')
		{
			k = 0;
			while (av[i][++k] != '\0')
				program_info->string_flags[++j] = av[i][k];
		}
	}
}

/*
**	This function handles counting the flags so that i can allocate enough space
**	in the string_flags array inside of my info struct.
**	This will also serve as the function
**	that sets my directory start so i can start saving
**	directories from that index.
*/

int		count_flags(char *av[], int *directory_start)
{
	int num_of_flags;
	int i;
	int j;

	num_of_flags = 0;
	i = 0;
	while (av[++i])
	{
		if (av[i][0] == '-' && av[i][1])
		{
			j = 0;
			while (av[i][++j] && valid_flag(av[i][j]))
				num_of_flags++;
		}
		else
		{
			*directory_start = i;
			return (num_of_flags);
		}
	}
	*directory_start = 0;
	return (num_of_flags);
}

void	handle_flags(t_info *program_info, char *av[])
{
	program_info->num_of_flags =
		count_flags(av, &program_info->directory_start);
	if (program_info->num_of_flags > 0)
	{
		store_string_flags(av, program_info);
		setup_flag_structure(program_info);
	}
}
