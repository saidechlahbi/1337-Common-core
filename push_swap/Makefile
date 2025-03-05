CC = cc
FLAGS = -Wall -Wextra -Werror

FILES = check_input.c chunks.c free_if.c main.c operations.c operations1.c operations2.c splite.c tools.c

OBJ = $(FILES:.c=.o)

NAME = push_swap

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)