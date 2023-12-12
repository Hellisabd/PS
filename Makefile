NAME	= push_swap

SRCS	= 

OBJS	= $(SRCS:.c=.o)

CC	= gcc

CFLAGS	+= -Wall -Wextra -Werror -fsanitize=address -g3

RM	= rm -rf

all	: $(NAME)

$(NAME) : $(OBJS)
	  @make -C Libft
	  @cp Libft/libft.a .
	  @mv libft.a $(NAME)
	  ar -crs $(NAME) $(OBJS)

clean : 
	$(RM) $(OBJS)
	@make -C Libft clean

fclean : 
	$(RM) $(NAME) $(OBJS)
	@make -C Libft fclean

re :	fclean all

ex :	fclean all clean
