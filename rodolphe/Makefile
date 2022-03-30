
SRCS_DIR	= srcs/

SRCS	=	main.c

OBJS	=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	= 	objs/

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I $(INC)

CC			=	cc

NAME		=	pipex

RM			=	rm -rf

INC			=	includes

LIB			=	libft/libft.a

all:		$(NAME)

$(NAME):		$(LIB) $(OBJS)
#				$(CC) $(CFLAGS) -c srcs/main.c
				$(CC) $(CFLAGS) $^ -o $(NAME) -L ./libft -lft

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@mkdir -p $(OBJS_DIR)
				${CC} ${CFLAGS} -c $< -o $@

libft/libft.a :
			$(MAKE) -C libft all

ft_printf/libftprintf.a :
			$(MAKE) -C ft_printf all

fcleanprintf:
			$(MAKE) -C ft_printf fclean 

clean:
			$(RM) $(OBJS_DIR)
			make -C ft_printf clean

fclean:		clean fcleanprintf
			${RM} ${OBJS_DIR}
			rm -rf ${NAME} main.o
			rm -rf checker main_checker.o

re:			fclean all

.PHONY:		all clean fclean re client server
