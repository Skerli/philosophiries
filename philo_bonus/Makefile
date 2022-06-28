# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 11:19:46 by dcompreh          #+#    #+#              #
#    Updated: 2022/06/24 15:17:46 by dcompreh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

LIST_NAME = ft_atoi.c main.c start_process.c \
			algorithm.c init.c \
			f_sleep.c end.c eat.c
			

OBJ_NAME= $(patsubst %.c,%.o,$(LIST_NAME))

CC = gcc #-fsanitize=thread

CFLAGS = -Wall -Wextra -Werror

INC = philo.h

all : $(NAME)

$(NAME) : $(OBJ_NAME) $(INC)
	$(CC) $(CFLAGS) $(OBJ_NAME) -o $(NAME) -lpthread

clean :
	@rm -f $(OBJ_NAME)
fclean : clean
	@rm -f $(NAME) $(OBJ_NAME)
re : fclean all
.PHONY : all clean fclean re