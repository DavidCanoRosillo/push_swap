.PHONY: all clean fclean re
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRC = push_swap.c parse.c ft_split.c errores.c list.c list2.c list3.c sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)    

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all