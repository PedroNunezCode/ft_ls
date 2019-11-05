#include "../includes/ft_ls.h"

/**
 *  This function will handle running the program after all the structs have been setup.
 **/

void process_directories(t_info *program_info)
{
    DIR *directory;
    int i;

    directory = NULL;

    i = -1;
    while (++i < program_info->num_of_dirs)
    {
        if(program_info->flag_struct->cr)
            handle_capital_r_flag(directory, program_info);
        // else
        //     start_output(directory, program_info, i);
    }
    

}