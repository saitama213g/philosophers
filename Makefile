CC = gcc
# CFLAGS =  -fsanitize=address
SRCS = mandatory/main.c mandatory/ft_atoi.c mandatory/ft_isdigit.c mandatory/ft_give_data.c \
	   mandatory/give_forks.c mandatory/setter_getters.c mandatory/ft_jointhreads.c
HEAD = mandatory/philo.h
NAME = philosophers
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC)  $(OBJS) -o $(NAME)

$(OBJS):$(HEAD)

bonus:
	make -C bonus

clean:
	make -C libft clean
	rm -f $(OBJS)

re: fclean all

fclean:
	make -C libft fclean
	rm -f $(OBJS)
	rm -f $(NAME)

.PHONY : all bonus clean fclean re