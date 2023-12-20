NAME	= push_swap

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRCS	= main.c \
		ft_error.c	\
		ps_utils_a.c	\
		ps_utils_b.c	\
		ps_utils_both.c	\
		ft_check.c	\
		ft_sort.c	\
		ft_sort_three.c		

OBJS	= $(SRCS:.c=.o)

CC	= @gcc

CFLAGS	+= -Wall -Wextra -Werror -g3 -fsanitize=address

RM	= @rm -rf

all	: $(NAME)

$(NAME) : $(OBJS)
	@make --no-print-directory -C Libft
	$(CC) $(CFLAGS) $(OBJS) Libft/libft.a -o $(NAME)

clean : 
	$(RM) $(OBJS)
	@make --no-print-directory -C Libft clean
	@echo "$(BLUE)OBJS CLEAR MY FRIEND!$(DEF_COLOR)"

fclean : 
	$(RM) $(NAME) $(OBJS)
	@make --no-print-directory -C Libft fclean
	@echo "$(MAGENTA)¯|_(ツ)_/¯ I'M SO PROUD OF U!$(DEF_COLOR)"


re :	fclean all

ex :	fclean all clean
	@echo "$(GREEN)(•̀ᴗ•́)و ̑̑ALL FINE!(•̀ᴗ•́)و ̑̑$(DEF_COLOR)"