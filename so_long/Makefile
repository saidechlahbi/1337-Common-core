CC = cc 
CFLAGS = -Wall -Wextra -Werror

FRAMEWORKS = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext 

FILES = check_map.c check_map1.c check_map2.c  clean.c so_long.c get_next_line.c tools.c \
		get_next_line_utils.c inputs.c

OBJ = $(FILES:.c=.o)


NAME = so_long

HEADER = so_long.h 

PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a

all: $(PRINTF) $(NAME)

$(PRINTF):
	make -C $(PRINTF_PATH)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(FRAMEWORKS) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re