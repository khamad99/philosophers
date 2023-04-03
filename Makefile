# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: desteve <desteve@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 16:27:55 by desteve           #+#    #+#              #
#    Updated: 2023/03/30 15:53:35 by desteve          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = philo.c philo_utils.c start_prog.c initialize.c check_done_eat_and_die.c routine.c
OBJS = $(SRC:.c=.o)
CC = gcc -pthread
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -lpthread ${CFLAGS} ${OBJS} -o $@

%.o: %.c philosophers.h
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all