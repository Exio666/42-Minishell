# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/03/30 11:47:20 by rpottier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_PATH =	objs/

SRCS_PATH =	srcs/

SRCS =	main.c \
		annexe.c

OBJS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

DEPS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.d))

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCS = -I includes

NAME = pipex

ALLLIB = libft/libft.a

all: $(NAME)

$(NAME) : $(OBJS) $(ALLLIB)
	$(CC) $(CFLAGS) $(OBJS) $(ALLLIB) -o $(NAME) $(INCS)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MF $(@:.o=.d) -c $< -o $@ $(INCS)

clean :
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C libft clean

fclean : clean
	$(RM) $(NAME)
	$(RM) libft/libft.a

libft/libft.a :
	$(MAKE) -C libft all

bonus: all

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re bonus