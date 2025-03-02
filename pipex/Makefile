CC = cc
FLAGS = -Wall -Wextra -Werror
FILES = mandatory/free.c mandatory/pipex.c mandatory/utils.c
OBJ = $(FILES:.c=.o)
NAME = pipex
HEADER = mandatory/pipex.h

# Add libft paths
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Rules
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ) 