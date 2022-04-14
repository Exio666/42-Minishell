# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/04/14 14:32:13 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########						Comilation Tools						########
################################################################################

NAME = minishell
NAME_TEST = minishell_test

CC = cc

CFLAGS = -MMD -Wall -Wextra -Werror -g3

#ARGUMENT_RUN =  
#ARGUMENT_RUN_TEST =

################################################################################
########							Sources 							########
################################################################################

SRCS_PATH 	=	srcs/

INCS =	-I includes				\
		-I libft/includes		\
		-I includes/builtins	\
		-I includes/checker		\
		-I includes/utils		\
		-I includes/wildcard	\
		-I includes/parser		\
		-I includes/env

SRCS =	

SRCS_TEST = 

################################################################################
########							Libraries							########
################################################################################

LIBS = libft/libft.a

################################################################################
########						Objects/Dependences						########
################################################################################

OBJS_PATH =	objs/

OBJS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
OBJS_TEST = $(addprefix $(OBJS_PATH), $(SRCS_TEST:.c=.d))
DEPS =	$(OBJS:.o=.d)
DEPS_TEST = $(OBJS_TEST:.o=.d)

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

all: $(NAME)


$(NAME): header $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(INCS)
	echo "$(BLUE)$(NAME): $(GREEN)Success $(NO_COLOR)"

test: $(NAME_TEST)

bonus: all

header:
		echo "${BLUE}"
		echo "          (_)     (_)   | |        | | | "
		echo " _ __ ___  _ _ __  _ ___| |__   ___| | | "
		echo "| '_ \` _ \| | '_ \| / __| '_ \ / _ \ | | "
		echo "| | | | | | | | | | \__ \ | | |  __/ | | "
		echo "|_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_| "
		echo "                 by rpottier and bsavinel"
		echo "${NO_COLOR}"


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME_TEST): header $(LIBS) $(OBJS_TEST) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_TEST) $(OBJS) $(LIBS) -o $(NAME_TEST) $(INCS)
	echo "$(BLUE)$(NAME_TEST): $(GREEN)Success $(NO_COLOR)"

clean: 
	$(RM) $(OBJS_PATH)
	@echo "rm -rf libft/objs" 
	@$(MAKE) -C libft clean --no-print-directory --silent

fclean: clean
	$(RM) minishell
	$(RM) minishell_test 
	$(RM) libft/libft.a

re: header fclean all

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

ifneq ($(MAKECMDGOALS), fclean)
 ifneq ($(MAKECMDGOALS), clean)
  -include $(DEPS) $(DEPS_TEST)
 endif
endif


.PHONY: all clean fclean re bonus val_run_test run_test val_run run push test
