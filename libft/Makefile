SRC = ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_strlen.c ft_isalnum.c \
	  ft_strlcpy.c ft_isprint.c ft_toupper.c ft_tolower.c \
	  ft_strchr.c  ft_memset.c ft_bzero.c ft_tolower.c ft_memchr.c \
	  ft_memcmp.c  ft_strnstr.c ft_atoi.c  ft_strdup.c ft_calloc.c ft_memcpy.c \
	  ft_memmove.c ft_substr.c ft_strtrim.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c ft_free_strs.c\
	  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c ft_atoi_hex.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
	  	ft_lstiter_bonus.c ft_lstmap_bonus.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEAD = libft.h

OBJ = $(SRC:.c=.o)

BNOBJ =$(BONUS:.c=.o)

AR = ar rcs

RM = rm -rf

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o:%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BNOBJ)
	$(AR) $(NAME) $(BNOBJ)

clean:
	$(RM) $(OBJ) $(BNOBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY : all bonus clean fclean re