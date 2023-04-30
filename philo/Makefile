CC				=	cc

NAME			=	philo

SRC				=	parsing.c \
					philo_utils.c \
					philo.c \
					thread_function.c \
					philo_exit.c \
					philo_init.c \
					philo_join.c \
					philo_usleep.c \
					philo_monitoring.c \
					dead_thread.c \


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