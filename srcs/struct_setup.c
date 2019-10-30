/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <pedronunezcode>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:47:02 by pnunez            #+#    #+#             */
/*   Updated: 2019/10/29 16:46:44 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_info *setup_program_info(char *argv[])
{
    t_info *program_info;

    program_info = malloc(sizeof(t_info));
    handle_flags(program_info, argv);
    
    return program_info;

}

t_info *no_argument_setup(void)
{
    t_info *program_info;

    program_info = malloc(sizeof(t_info));

    program_info->num_of_dirs = 1;
    program_info->num_of_flags = 0;
    program_info->string_flags = NULL;
    program_info->directories = malloc(sizeof(char *) * 2);
    program_info->directories[0] = ft_strdup(".");
    // program_info->directories[0][0] = '.';
    program_info->directories[1] = NULL;

    return(program_info);
}