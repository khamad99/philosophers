CC				=	cc

NAME			=	philo

SRC				=	parsing.c \
					philo_utils.c \
					philo.c \
					thread_function.c \

OBJ				=	$(SRC:%.c=%.o)

CFLAGS			=	-Werror -Wextra -Wall -pthread


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all