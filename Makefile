# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/04/05 17:27:39 by rpottier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########						Comilation Tools						########
################################################################################

NAME = minishell
NAME_TEST = minishell_test

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARGUMENT_RUN = 
ARGUMENT_RUN_TEST =

################################################################################
########							Sources 							########
################################################################################

SRCS_PATH 	=	srcs/

INCS = -I includes -I libft/includes

SRCS =	

SRCS_TEST =	checker/and_or_checker.c	\
			checker/primary_check.c		\
			checker/quote_checker.c	\
			checker/jump_caracters.c

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
		@echo "${BLUE}"
		@echo "          (_)     (_)   | |        | | | "
		@echo " _ __ ___  _ _ __  _ ___| |__   ___| | | "
		@echo "| '_ \` _ \| | '_ \| / __| '_ \ / _ \ | | "
		@echo "| | | | | | | | | | \__ \ | | |  __/ | | "
		@echo "|_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_| "
		@echo "                 by rpottier and bsavinel"
		@echo "${NO_COLOR}"

$(NAME) : header $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(INCS)
	echo "$(BLUE)$(NAME): $(GREEN)Success $(NO_COLOR)"

$(OBJS_PATH)%.o: srcs/%.c
	echo a
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCS)

$(NAME_TEST): header $(LIBS) $(OBJS_TEST)
	$(CC) $(CFLAGS) $(OBJS_TEST) $(LIBS) -o $(NAME)_test $(INCS)
	echo "$(BLUE)$(NAME_TEST): $(GREEN)Success $(NO_COLOR)"

clean : header
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C libft clean

fclean : header clean
	$(RM) $(NAME)
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

push: header
		make fclean
		git add . && git commit -m "Makefile push" && git push && echo "$(BLUE)Push: $(GREEN)Success $(NO_COLOR)" || echo "$(BLUE)Push: $(RED)Fail $(NO_COLOR)"

################################################################################
#######							Rules for libs							########
################################################################################

libft/libft.a :
	$(MAKE) -C libft all && echo "$(BLUE)Compiation of libft: $(GREEN)Success $(NO_COLOR)" || echo "$(BLUE)Compiation of libft: $(RED)Fail $(NO_COLOR)"

-include $(DEPS)

.PHONY: all clean fclean re bonus val_run_test run_test val_run run push test
