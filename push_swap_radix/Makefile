CC = cc
FLAGS = -Wall -Wextra -Werror

FILES = mandatory/check_input.c  mandatory/free_if.c mandatory/main.c mandatory/algorithme.c \
 		mandatory/algorithme1.c mandatory/operations.c mandatory/operations1.c \
		mandatory/operations2.c mandatory/splite.c mandatory/tools.c mandatory/less_than_5.c 

OBJ = $(FILES:.c=.o)

NAME = push_swap

HEADER = mandatory/push_swap.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re