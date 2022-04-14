# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/04/14 16:09:36 by rpottier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########						Comilation Tools						########
################################################################################

NAME = minishell
NAME_TEST = minishell_test

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

ARGUMENT_RUN = 
ARGUMENT_RUN_TEST =

################################################################################
########							Sources 							########
################################################################################

SRCS_PATH 	=	srcs/

INCS =	-I includes				\
		-I libft/includes		\
		-I includes/btree_management	\
		-I includes/builtins	\
		-I includes/checker		\
		-I includes/utils		\
		-I includes/wildcard	\
		-I includes/parser/logical_operator		\
		-I includes/parser/pipe_sequence		\
		-I includes/env_list

SRCS =	checker/and_or_checker.c				\
		checker/primary_check.c					\
		checker/quote_checker.c					\
		btree_management/compare_functions.c	\
		btree_management/insert_functions.c		\
		btree_management/create_node_functions.c	\
		parser/logical_operator/count_and_update_logic_op.c		\
		parser/logical_operator/find_specific_char_funct.c		\
		parser/logical_operator/get_btree_of_logical_op.c		\
		parser/logical_operator/increase_and_decrease_level.c		\
		parser/logical_operator/input_priority_level.c			\
		parser/logical_operator/lstdelone_parser.c				\
		parser/logical_operator/logical_operator_indexation.c	\
		parser/logical_operator/parse_op_by_level.c				\
		parser/logical_operator/get_logical_op.c					\
		parser/logical_operator/print_debug_funct.c				\
		parser/pipe_sequence/get_pipe_sequence.c \
		parser/pipe_sequence/add_all_pipe_sequence_in_tree.c \
		parser/pipe_sequence/get_start_and_end_index.c				\
		env_list/env_list_management.c			\
		env_list/get_functions.c				\
		env_list/convert_env_array_in_list.c	\
		env_list/get_path_variable.c			\
		utils/jump_caracters.c					\
		utils/is_functions.c

SRCS_TEST = parser/pipe_sequence/main_pipe_sequence.c				

################################################################################
########							Libraries							########
################################################################################

LIBS = libft/libft.a

################################################################################
########						Objects/Dependences						########
################################################################################

OBJS_PATH =	objs/

OBJS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
OBJS_TEST = $(addprefix $(OBJS_PATH), $(SRCS_TEST:.c=.o))
DEPS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.d))
DEPS_TEST =	$(addprefix $(OBJS_PATH), $(SRCS_TEST:.c=.d))

################################################################################
########							Others								########
################################################################################

RM = rm -rf

################################################################################
########							Colors								########
################################################################################

BLUE		=	\033[0;34m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
NO_COLOR	=	\033[m

################################################################################
########							Rules								########
################################################################################

all: header $(NAME)
test: header $(NAME_TEST)
bonus: header all

header:
		echo "${BLUE}"
		echo "          (_)     (_)   | |        | | | "
		echo " _ __ ___  _ _ __  _ ___| |__   ___| | | "
		echo "| '_ \` _ \| | '_ \| / __| '_ \ / _ \ | | "
		echo "| | | | | | | | | | \__ \ | | |  __/ | | "
		echo "|_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_| "
		echo "                 by Airpottier and co"
		echo "${NO_COLOR}"

$(NAME) : header $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(INCS)
	echo "$(BLUE)$(NAME): $(GREEN)Success $(NO_COLOR)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCS)

$(NAME_TEST): header $(LIBS) $(OBJS_TEST) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_TEST) $(OBJS) $(LIBS) -o $(NAME_TEST) $(INCS)
	echo "$(BLUE)$(NAME_TEST): $(GREEN)Success $(NO_COLOR)"

clean :
	$(RM) $(OBJS_PATH)
	$(MAKE) -C libft clean

fclean : clean
	$(RM) $(NAME) 
	$(RM) $(NAME_TEST)
	$(RM) libft/libft.a

re : header fclean all

run: header all
	$(NAME) $(ARGUMENT_RUN)

val_run: header all
	valgrind $(NAME) $(ARGUMENT_RUN)

run_test: header test
	$(NAME_TEST) $(ARGUMENT_RUN_TEST)

val_run_test: header test
	valgrind $(NAME_TEST) $(ARGUMENT_RUN_TEST)

push:
		make fclean
		git add . && git commit -m "Makefile push" && git push && echo "$(BLUE)Push: $(GREEN)Success $(NO_COLOR)" || echo "$(BLUE)Push: $(RED)Fail $(NO_COLOR)"

################################################################################
#######							Rules for libs							########
################################################################################

libft/libft.a :
	$(MAKE) -C libft all && echo "$(BLUE)Compiation of libft: $(GREEN)Success $(NO_COLOR)" || echo "$(BLUE)Compiation of libft: $(RED)Fail $(NO_COLOR)"

-include $(DEPS)
-include $(DEPS_TEST)

.PHONY: all clean fclean re bonus val_run_test run_test val_run run push test

.SILENT: