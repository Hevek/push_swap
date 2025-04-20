# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: restevez <restevez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 19:30:05 by restevez          #+#    #+#              #
#    Updated: 2025/04/19 21:37:24 by restevez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME			= push_swap

# Directories
LIBFT_DIR		= ./libft
INC				= include/
SRC_DIR			= src/
OBJ_DIR			= obj/

# Compiler and CFlags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -I$(INC)
RM				= rm -f

# Source Files
COMMANDS_PATHS	= $(SRC_DIR)commands/push.c \
					$(SRC_DIR)commands/rev_rotate.c \
					$(SRC_DIR)commands/rotate.c \
					$(SRC_DIR)commands/sort_stacks.c \
					$(SRC_DIR)commands/sort_three.c \
					$(SRC_DIR)commands/swap.c

PUSH_SWAP_PATHS	= $(SRC_DIR)handle_errors.c \
					$(SRC_DIR)init_a_to_b.c \
					$(SRC_DIR)init_b_to_a.c \
					$(SRC_DIR)push_swap.c \
					$(SRC_DIR)split.c \
					$(SRC_DIR)stack_init.c \
					$(SRC_DIR)stack_utils.c

# Concatenate all source files
SRCS			= $(COMMANDS_PATHS) $(PUSH_SWAP_PATHS)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start: all

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)/libft.a

re: fclean all

# Phony targets represent actions not files
.PHONY: start all clean fclean re
