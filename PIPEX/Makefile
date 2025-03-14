CC = cc
FLAGS = -Wall -Wextra -Werror

# Files
FILES = mandatory/free.c mandatory/pipex.c mandatory/utils.c

# Object files
OBJ = $(FILES:.c=.o)

# Name
NAME = pipex

# Header
HEADER = mandatory/pipex.h

# Libft path
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Rules
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re