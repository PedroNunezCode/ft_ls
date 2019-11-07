/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <pedronunezcode>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:45:31 by pnunez            #+#    #+#             */
/*   Updated: 2019/11/06 17:43:23 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "../libft/include/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

typedef struct s_flags
{
    bool cr;
    bool l;
    bool a;
    bool r;
    bool t;
} t_flags;

typedef struct s_info
{
    int num_of_flags;
    int num_of_dirs;
    int directory_start;
    char *string_flags;
    char **directories;
    t_flags *flag_struct;
} t_info;

t_info *no_argument_setup();
t_info *setup_program_info(char *av[]);
void handle_flags(t_info *program_info, char *av[]);
int count_flags(char *av[], int *directory_start);
int valid_flag(char flag);
void store_string_flags(char *av[], t_info *program_info);
void setup_flag_structure(t_info *program_info);
void handle_directories(t_info *program_info, char *av[]);
int count_directories(char *av[], int directory_start);
void store_directories(t_info *program_info, char *av[]);
void store_root_directory(t_info *program_info);
void process_directories(t_info *program_info);
void handle_capital_r_flag(DIR *directory, t_info *program_info);
// void start_output(DIR *directory, t_info *program_info, int i);
void access_error(char *directory);
void recursive_directory_print(char *dir, t_flags *flags, int i);
void print_path(char *path);
char **sorted_folders(DIR *dir_stream, t_flags *flags, int i);
void sort_folders(char **folders, t_flags *flags, int num_of_folders);
void reverse_sort(char **folders, int num_of_folders);
void alpha_sort(char **folders, int num_of_folders);
void time_sort(char **folders);
void reverse_time_sort(char **folders, int num_of_folders);
int modification_time(char *file1, char *file2);
char *create_path(char *path, char *new_path);
int totaldirs(char **folder, t_flags *flags, char *path, int result);
void print_l_num(char **folders, t_flags *flags, char *path, int i);
int get_st_blocks(char *path, char *new_path, int old_value);
void init_perms(char **folders, char *path, t_flags *flags);
void sps(char *name, t_flags *flags, char *path);
int print_chr_blk(struct stat *filestats, struct passwd *psswd,
                  struct group *grp);
void continue_chr_print(struct stat *filestats, char *tmp, char *name);
int non_chr_blk(struct stat *filestats, struct passwd *psswd,
                struct group *grp);
void continue_nonchr_print(char *tmp, char *name);
void print_perms(struct stat *filestats);
void start_output(DIR *directory_stream, t_info *program_info, int i);
void simple_output(char *directory, t_flags *flags, int i);

#endif