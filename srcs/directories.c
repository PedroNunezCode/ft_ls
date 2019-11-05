/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directories.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <pedronunezcode>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:56:26 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/04 20:36:26 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


int get_st_blocks(char *path, char *new_path, int old_value)
{
    void *tmp;
    struct stat *filestat;
    int new_value;
    
    filestat = malloc(sizeof(struct stat));
    tmp = create_path(path, new_path);
    lstat(tmp, filestat);
    new_value = old_value + filestat->st_blocks;
    free(filestat);
    return(new_value);
}
/**
 * the total dirs function is used to print the number of directoried inside
 * the "l" flag.
 **/
int totaldirs(char **folder, t_flags *flags, char *path, int result)
{
    int i;
    
    i = -1;
    result = 0;
    while (folder[++i])
    {
        if(flags->a == 1)
            result = get_st_blocks(path, folder[i], result);
        else if (folder[i][0] != '.' && flags->a != 1)
            result = get_st_blocks(path, folder[i], result);
    }
    return (result);
}

void store_directories(t_info *program_info, char *av[])
{
    int i;

    i = -1;

    program_info->directories = malloc(sizeof(char *) * (program_info->num_of_dirs + 1));
    while (av[program_info->directory_start])
    {
        program_info->directories[++i] = ft_strdup(av[program_info->directory_start]);
        program_info->directory_start += 1;
    }
    program_info->directories[program_info->num_of_dirs] = NULL;
}

/**
  * This fuction handles counting the ammount of directories there is.
  * this number will be used to allocate space to recurse / print them. 
  **/
int count_directories(char *av[], int directory_start)
{
    int num_of_directories;

    num_of_directories = 0;
    while (av[directory_start])
    {
        num_of_directories++;
        directory_start++;
    }

    return num_of_directories;
}

/**
 *  This function handles saving the directories from std input.
 *  if there is no specified directories, this means they want to ls
 *  the root directory: "."
 **/
void handle_directories(t_info *program_info, char *av[])
{
    if (program_info->directory_start > 0 && av)
    {
        program_info->num_of_dirs = count_directories(av, program_info->directory_start);
        store_directories(program_info, av);
    }
    else
    {
        program_info->num_of_dirs = 1;
        program_info->directories = malloc(sizeof(char *) * 2);
        program_info->directories[0] = ft_strdup(".");
        program_info->directories[1] = NULL;
    }
}
