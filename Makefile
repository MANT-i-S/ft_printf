# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 12:49:38 by sholiak           #+#    #+#              #
#    Updated: 2019/07/30 20:57:19 by sholiak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAME2 = ./libft/libft.a

FILES = ./srcs/*.c

LIBFILES = ./libft/*.c

OBJ = *.o

LIBOBJ = ./libft/*.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(FILES) $(LIBFILES)
	ar rcs $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ) $(LIBOBJ)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all
