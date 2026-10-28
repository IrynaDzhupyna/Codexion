SRC = .
NAME = codexion
HEADER = codexion.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

ARGS = 6 900 200 200 200 10 60 fifo

SRC = main.c utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

test-val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re
