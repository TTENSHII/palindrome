NAME = palindrome

SRC = src/main.c\
	src/init_struct.c\
	src/init_options_flags.c\
	src/utils.c\
	src/error_handler.c\
	src/palindrome_p.c\
	src/palindrome_n.c\
	src/free_data.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Iincludes/ -Wall -Wextra -Werror

all : $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
