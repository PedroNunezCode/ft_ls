/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <pedronunezcode>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:32:45 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/06 19:11:09 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// char **sort_root_folder(DIR *dir, t_flags *flags, int i)
// {
//     struct dirent *der;
//     char **sorted_folders;

//     while((der = readdir(dir)) != NULL)
//         i++;
//     rewinddir()
// }

void sort_folders(char **folders, t_flags *flags, int num_of_folders)
{
    if (flags->r == 1 && flags->t != 1)
        reverse_sort(folders, num_of_folders);
    else if(flags-> r != 1 && flags-> t != 1)
        alpha_sort(folders, num_of_folders);
    else if(flags->r != 1 && flags->t == 1)
        time_sort(folders);
    else if(flags->r == 1 && flags-> t == 1)
        reverse_time_sort(folders, num_of_folders);
}

char **sorted_folders(DIR *dir_stream, t_flags *flags, int i)
{
    struct dirent *der;
    char **result;

    while ((der = readdir(dir_stream)) != NULL)
        i++;
    rewinddir(dir_stream);
    result = malloc(sizeof(char *) * (i + 1));
    result[i] = NULL;
    i = 0;
    while ((der = readdir(dir_stream)) != NULL)
        result[i++] = ft_strdup(der->d_name);
    sort_folders(result, flags, i);

    return result;
}
