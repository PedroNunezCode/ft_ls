/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:36:27 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/13 20:07:34 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	init_program(int ac, char **av)
{
	t_info *program_info;

	if (ac < 2)
		program_info = no_argument_setup();
	else
		program_info = setup_program_info(av);
	process_directories(program_info);
	free(program_info);
}

int		main(int argc, char **argv)
{
	init_program(argc, argv);
	return (0);
}
