NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = \
srcs/agencement.c \
srcs/check.c \
srcs/check_file.c \
srcs/create_map.c \
srcs/create_tetriminos.c \
srcs/fct_print.c \
srcs/main.c \
srcs/tetri_mvt.c \
srcs/initialize.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^

%.o: %.c
	gcc -o $@ -c $< $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all $(NAME)
