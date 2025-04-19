# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: restevez <restevez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 19:30:05 by restevez          #+#    #+#              #
#    Updated: 2025/04/18 19:32:44 by restevez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME				= push_swap

# Directories
FT_PRINTF			= ./ft_printf/
INC					= include/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
COMMANDS_PATHS		=	$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_stacks.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/swap.c

PUSH_SWAP_PATHS		=	$(SRC_DIR)handle_errors.c \
						$(SRC_DIR)init_a_to_b.c \
						$(SRC_DIR)init_b_to_a.c \
						$(SRC_DIR)push_swap.c \
						$(SRC_DIR)split.c \
						$(SRC_DIR)stack_init.c \
						$(SRC_DIR)stack_utils.c

# Concatenate all source files
SRCS 				= $(COMMANDS_PATHS) $(PUSH_SWAP_PATHS)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					@make all

$(FT_PRINTF):
					@make -C ./ft_printf


all: 				$(NAME)

$(NAME): 			$(OBJ) $(FT_PRINTF)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(FT_PRINTF) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./ft_printf

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(FT_PRINTF)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re