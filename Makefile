# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 21:05:07 by fbouanan          #+#    #+#              #
#    Updated: 2022/04/18 21:05:09 by fbouanan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

all : $(NAME)

$(NAME): 
	gcc -Wall -Werror -Wextra philo.c  check_death.c init_data.c philo_utils.c -o philo

clean :
	rm -f $(NAME)
fclean : clean

re : fclean all

