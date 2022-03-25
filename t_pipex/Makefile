# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/03/23 15:34:20 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_PATH =	objs/

SRCS_PATH =	srcs/

SRCS =	main.c

OBJS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

DEPS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.d))

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCS = -I includes

NAME = pipex

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCS)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MF $(@:.o=.d) -c $< -o $@ $(INCS)

clean :
	$(RM) $(OBJS) $(DEPS)

fclean : clean
	$(RM) $(NAME)

bonus: all

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re bonus