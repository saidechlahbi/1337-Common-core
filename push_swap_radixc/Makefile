CC = cc
FLAGS = -Wall -Wextra -Werror

FILES = mandatory/check_input.c  mandatory/free_if.c mandatory/main.c mandatory/algorithme.c \
 		mandatory/algorithme1.c mandatory/operations.c mandatory/operations1.c \
		mandatory/operations2.c mandatory/splite.c mandatory/tools.c mandatory/less_than_4.c 

FILE_BONUS = bonus/do_op.c bonus/get_next_line_utils.c  bonus/operations.c bonus/tools.c \
			bonus/checker.c bonus/free_if.c bonus/operations1.c \
			bonus/check_input.c  bonus/get_next_line.c  bonus/operations2.c bonus/splite.c

OBJ = $(FILES:.c=.o)
OBJ_BONUS =  $(FILE_BONUS:.c=.o)

NAME = push_swap
NAME_BONUS = checker

HEADER = mandatory/push_swap.h
HEADER_BONUS = bonus/push_swap_bonus.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus : $(OBJ_BONUS)  $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
.PHONY: all clean fclean re