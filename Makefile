##
## EPITECH PROJECT, 2022
## palindrome
## File description:
## Makefile
##

NAME = palindrome

SRC = src/main.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Iincludes/

all : $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
