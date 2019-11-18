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

/*
** The reson I separated this function is to check for memory leaks at the end of the main.
** If the main function had this function's content inside, Then the good old while(1) would
** not be able to catch the memory leaks.
*/

/*
 ** The  Function below will separate the functionality of the program if the parameters
 ** are empty and only have the ./ft_ls command in it.
 */

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
