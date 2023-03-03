NAME = minishell

CC = gcc

SRC = $(shell find src -name "*.c")
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all 

.PHONY: all clean fclean re