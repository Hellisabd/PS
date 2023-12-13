NAME	= push_swap

SRCS	= main.c \
		ft_error.c	\
		ps_utils_a.c	\
		ps_utils_b.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc

CFLAGS	+= -Wall -Wextra -Werror -g3 -fsanitize=address

RM	= rm -rf

all	: $(NAME)

$(NAME) : $(OBJS)
	  make -C Libft
	  $(CC) $(CFLAGS) $(OBJS) Libft/libft.a -o $(NAME)

clean : 
	$(RM) $(OBJS)
	make -C Libft clean

fclean : 
	$(RM) $(NAME) $(OBJS)
	make -C Libft fclean

re :	fclean all

ex :	fclean all clean
