NAME = ft_ls

COMPILER = gcc

CFLAGS = -Wall -Wextra

SRCS =	 ./srcs/main \
				./srcs/struct_setup \
				./srcs/flags \
				./srcs/directories \
				./srcs/run_program \
				./srcs/handle_errors \
				./srcs/print_with_R_flag \
				./srcs/sort \
				./srcs/folder_sort_functions \
				./srcs/helpers \
				./srcs/recursion-helpers



CFILES = $(addsuffix .c, $(SRCS))

LIB = ./libft/libft.a 

INCLUDE = ./ft_ls

all: $(NAME)

$(LIB):
	@make -C libft

$(NAME) : $(LIB)
	@echo "\033[0;92mBuilding executable"
	@$(COMPILER) $(CFLAGS) $(CFILES) $(LIB) -I $(INCLUDE) -o $(NAME)
	@echo "\033[0;92mExecutable $(INCLUDE)"

clean:
	@make -C libft clean

fclean: clean
	@echo "\033[0;31m Cleaning Project files"
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

