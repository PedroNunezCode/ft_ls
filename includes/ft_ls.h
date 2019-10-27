#ifndef FT_LS_H
#define FT_LS_H

#include "../libft/include/libft.h"
#include <stdio.h>

typedef struct s_info
{
    int num_of_flags;
    int num_of_dirs;
    int directory_start;
    char *string_flags;
    char **directories;
} t_info;

t_info *no_argument_setup();
t_info *setup_program_info(char *av[]);
void handle_flags(t_info *program_info, char *av[]);
int count_flags(char *av[], int *directory_start);
int valid_flag(char flag);
void store_string_flags(char *av[], t_info *program_info);

#endif