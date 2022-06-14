NAME = palindrome

SRC = src/main.c\
	src/init_struct.c\
	src/init_options.c\
	src/utils.c\
	src/error_handler.c\
	src/palindrome.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Iincludes/

all : $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lm
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
