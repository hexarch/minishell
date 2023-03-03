CC=clang

CFLAGS= -Wall -Wextra -I./lib/readline/include
NAME=minishell
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
LIBS= -L./lib/readline/lib -lreadline


all: lib $(NAME)

lib:
	curl -O http://ftp.gnu.org/gnu/readline/readline-8.2-rc1.tar.gz
	gunzip -c readline-8.2-rc1.tar.gz | tar xopf -
	mv readline-8.2-rc1 readline
	/bin/sh -c "cd readline && sh ./configure --prefix=$$PWD/lib/readline"
	make install -C readline
	rm -f readline-8.2-rc1.tar.gz
	rm -rf readline

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re