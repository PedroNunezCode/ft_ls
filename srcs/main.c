/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <pedronunezcode>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:14:48 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/05 17:16:05 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int main(int argc, char **argv)
{
    t_info *program_info;

    if(argc < 2)
        program_info = no_argument_setup();
    else
        program_info = setup_program_info(argv);
    
    process_directories(program_info);
    return (0);
}