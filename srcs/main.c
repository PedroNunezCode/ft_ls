/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <pedronunezcode>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:14:48 by pnunez            #+#    #+#             */
/*   Updated: 2019/10/29 18:22:19 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int main(int argc, char **argv)
{
    t_info *program_info;
    // t_flags *program_flags;

    if(argc < 2)
        program_info = no_argument_setup();
    else
        program_info = setup_program_info(argv);
    
    free(program_info->directories[1]);
    free(program_info->directories[0]);
    free(program_info->directories);
    free(program_info);
    return (0);
    
}