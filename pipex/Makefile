CC = cc
FLAGS = -Wall -Wextra -Werror

# Files
FILES = mandatory/free.c mandatory/pipex.c mandatory/utils.c
FILES_BONUS = bonus/free_bonus.c bonus/get_next_line.c bonus/pipex_bonus.c bonus/utils_bonus.c

# Object files
OBJ = $(FILES:.c=.o)
OBJ_BONUS = $(FILES_BONUS:.c=.o)

# Names
NAME = pipex
NAME_BONUS = pipex_bonus

# Headers
HEADER = mandatory/pipex.h
HEADER_BONUS = bonus/pipex.h

# Libft paths
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Rules
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJ) $(OBJ_BONUS)