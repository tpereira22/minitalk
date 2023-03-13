NAME	=	minishell

RED		= 	\e[31m
GREEN	= 	\e[32m
RESET	= 	\e[0m

SRCS	=	minishell.c check_str.c
OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
READ	=	-lreadline

RM		= 	rm -fr

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(READ) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created$(RESET)"

clean:
	$(RM) $(OBJS)
	@echo "$(RED)$(NAME) object files have been deleted$(RESET)"

fclean:		clean
	$(RM) $(NAME)
	@echo "$(RED)$(NAME) havs been deleted$(RESET)"

re:			fclean all

.PHONY:	all clean fclean
