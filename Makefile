# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquil <jquil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 12:54:02 by jquil             #+#    #+#              #
#    Updated: 2023/09/26 21:04:00 by jquil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	\
				philo.c					\
				ft_atoi.c				\
				ft_initialise_data.c	\
				ft_status_philo.c		\
				ft_thread.c				\
				ft_utils.c				\
				ft_want_philo_want.c	\
				ft_free_data.c			\
				ft_check.c				\
				fork_trauma.c			\


OBJS		=	$(SRCS:.c=.o)
CC			=	cc
FLAGS		=	-g3 -Werror -Wextra -Wall

#------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	rm $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------------------------

.PHONY: clean fclean re
