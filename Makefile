NAME = libft.a

FILES = *.c

LIBFILES = ./libft/*.c

OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(FILES) $(LIBFILES)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f ./libft/*.o *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
