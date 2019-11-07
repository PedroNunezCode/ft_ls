/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <pedronunezcode>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:47:02 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/06 17:49:12 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_info *setup_program_info(char *av[])
{
    t_info *program_info;

    program_info = malloc(sizeof(t_info));
    handle_flags(program_info, av);
    handle_directories(program_info, av);
    
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
    program_info->directories[1] = NULL;

    program_info->flag_struct = malloc(sizeof(t_flags));
    program_info->flag_struct->cr = 0;
    program_info->flag_struct->l = 0;
    program_info->flag_struct->a = 0;
    program_info->flag_struct->r = 0;
    program_info->flag_struct->t = 0;

    return(program_info);
}