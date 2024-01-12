NAME	= push_swap

NAME_BONUS	= checker

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRCS	= ft_error.c	\
		ps_utils_a.c	\
		ps_utils_b.c	\
		ps_utils_both.c	\
		ft_check.c	\
		ft_sort.c	\
		ft_sort_three.c	\
		sort_exension.c	\
		ft_start_push.c

SRCS_MAIN	= main.c $(SRCS)

SRCS_BONUS	= checker.c $(SRCS)

OBJS	= $(SRCS_MAIN:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC	= @gcc

CFLAGS	+= -Wall -Wextra -Werror -g3

RM	= @rm -rf

all	: $(NAME)

bonus	: $(NAME_BONUS)

$(NAME) : $(OBJS)
	@make --no-print-directory -C Libft
	$(CC) $(CFLAGS) $(OBJS) Libft/libft.a -o $(NAME)
	@echo "$(MAGENTA)Make Done$(DEF_COLOR)"

$(NAME_BONUS)	: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) Libft/libft.a -o $(NAME_BONUS)
	@echo "$(YELLOW)Make Bonus Done$(DEF_COLOR)"

clean : 
	$(RM) $(OBJS) $(OBJS_BONUS)
	@make --no-print-directory -C Libft clean
	@echo "$(BLUE)OBJS CLEAR MY FRIEND!$(DEF_COLOR)"

fclean : 
	$(RM) $(NAME) $(OBJS) $(NAME_BONUS) $(OBJS_BONUS)
	@make --no-print-directory -C Libft fclean
	@echo "$(MAGENTA)¯|_(ツ)_/¯ I'M SO PROUD OF U!$(DEF_COLOR)"


re :	fclean all bonus

ex :	re clean
	@echo "$(GREEN)(•̀ᴗ•́)و ̑̑ALL FINE!(•̀ᴗ•́)و ̑̑$(DEF_COLOR)"