/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <pedronunezcode>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:06:15 by pnunez            #+#    #+#             */
/*   Updated: 2019/10/26 20:56:13 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int valid_flag(char flag)
{
    if(flag == 'a' || flag == 'l' || flag == 'R' || flag == 'r'  || flag == 't')
        return 1;
    else {
        ft_putstr("ls: illegal option -- ");
        ft_putchar(flag);
        ft_putstr("\n");
        ft_putstr("usage: ls [-lRart] [ File ...]\n");
        exit(0);
    }
}

/*
* This function handles saving the flags into the string_flags array.
*/

void store_string_flags(char *av[], t_info *program_info)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    program_info->string_flags = malloc((sizeof(char)) * (program_info->num_of_flags));
    while(av[++i])
    {
        if(av[i][0] == '-')
        {
            k = 0;
            while(av[i][k++] != '\0')
                program_info->string_flags[j++] = av[i][k];
        }
    }
}

/*
* This function handles counting the flags so that i can allocate enough space
* in the string_flags array inside of my info struct. This will also serve as the function
* that sets my directory start so i can start saving directories from that index.
*/

int count_flags(char *av[], int *directory_start)
{
    int num_of_flags;
    int i;
    int j;

    num_of_flags = 0;
    i = 0;
    while(av[++i])
    {
        if(av[i][0] == '-')
        {
            j = 0;
            while(av[i][++j] && valid_flag(av[i][j]))
                num_of_flags++;
        }else{
            *directory_start = i;
            return(num_of_flags);
        }
    }
    return(num_of_flags);
}


/*
* This function will handle the flags passed in from argv. first it will count the flags,
* then set the directory start. and then store the flags if any.
*/
void handle_flags(t_info *program_info, char *av[])
{
    program_info->num_of_flags = count_flags(av, &program_info->directory_start);
    if(program_info->num_of_flags > 0)
        store_string_flags(av, program_info);
}