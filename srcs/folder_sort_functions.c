/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   folder_sort_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <pedronunezcode>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:27:26 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/06 18:24:09 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/**
 * modification time will compare the last modification time of a file,
 * in seconds or nano seconds if need be.
 **/
int modification_time(char *f1, char *f2)
{
    struct stat *file1;
    struct stat *file2;
    double seconds;

    file1 = malloc(sizeof(struct stat));
    file2 = malloc(sizeof(struct stat));

    lstat(f1, file1);
    lstat(f2, file2);
    seconds = difftime(file1->st_mtime, file2->st_mtime);
    if (seconds == 0)
        seconds = difftime(file1->st_mtimespec.tv_nsec,
                           file2->st_mtimespec.tv_nsec);
    free(file1);
    free(file2);

    if (seconds < 0)
        return (-1);
    else if (seconds > 0)
        return (1);
    return (0);
}

/**
 * Reverse sort will sort the files reverse in alphabetical order. This is the
 *  function for -r.
 **/
void reverse_sort(char **folders, int number_of_dirs)
{
    int j;
    int i;
    char *tmp;

    i = -1;
    while (++i < number_of_dirs)
    {
        j = 0;
        while (++j < number_of_dirs)
        {
            if (ft_strcmp(folders[j - 1], folders[j]) < 0)
            {
                tmp = folders[j];
                folders[j] = folders[j - 1];
                folders[j - 1] = tmp;
            }
        }
    }
}

/**
 * This function sorts the folders in alphabetical order.
 **/
void alpha_sort(char **folders, int num_of_folders)
{
    int i;
    int j;
    char *tmp;

    i = -1;
    while (++i < num_of_folders - 1)
    {
        j = -1;
        while (++j < num_of_folders - i - 1)
        {
            if (ft_strcmp(folders[j], folders[j + 1]) > 0)
            {
                tmp = folders[j + 1];
                folders[j + 1] = folders[j];
                folders[j] = tmp;
            }
        }
    }
}

/**
 * This function will sort the folders by the time they were created.
 *  in seconds if nano seconds if necessary.
 **/

void time_sort(char **folders)
{
    int i;
    char *tmp;

    i = 0;
    while (folders[++i])
    {
        if (modification_time(folders[i - 1], folders[i]) < 0)
        {
            tmp = folders[i];
            folders[i] = folders[i - 1];
            folders[i - 1] = tmp;
            i = 1;
        }
    }
}

/**
 * in reverse time sort the files will be sorted in reverse time by seconds or
 * nano seconds if necessary.
 **/

void reverse_time_sort(char **folders, int num_of_folders)
{
    int i;
    int j;
    char *tmp;

    i = -1;
    while (++i < num_of_folders - 1)
    {
        j = -1;
        while (++j < num_of_folders - i - 1)
        {
            if (modification_time(folders[j], folders[j + 1]) > 0)
            {
                tmp = folders[j + 1];
                folders[j + 1] = folders[j];
                folders[j] = tmp;
            }
        }
    }
}