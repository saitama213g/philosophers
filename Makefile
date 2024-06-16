CC = gcc
# CFLAGS = -Wall
SRCS = mandatory/main.c mandatory/ft_atoi.c mandatory/ft_isdigit.c
HEAD = mandatory/philo.h
NAME = philosophers
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

$(OBJS):$(HEAD)

bonus:
	make -C bonus

clean:
	make -C libft clean
	rm -f $(OBJS)

re: fclean all

fclean:
	make -C libft fclean
	rm $(OBJS)
	rm $(NAME)

.PHONY : all bonus clean fclean re