CC = cc
FLAGS = -Wall -Wextra -Werror
# files
FILES = mandatory/free.c mandatory/pipex.c mandatory/utils.c
FILES_BONUS = free_bonus.c get_next_line.c  pipex_bonus.c utils_bonus.c
#objects files
OBJ = $(FILES:.c=.o)
OBJ_BONUS = $(files_BONUS:.c=.o)
#names
NAME = pipex
NAME_BONUS = pipex_bonus
#headers
HEADER = mandatory/pipex.h
HEADER_BONUS = bonus/pipex.h

# Add libft paths
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
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ) $(OBJ_BONUS)