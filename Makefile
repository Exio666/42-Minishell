# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/03/23 15:23:47 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_PATH =	objs/

SRCS_PATH =	srcs/

########################
# Ne pas mettre srcs/  #
########################

SRCS =	

OBJS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

DEPS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.d))

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCS = -I includes -I libft/includes

NAME = minishell

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