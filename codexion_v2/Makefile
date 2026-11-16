NAME = codexion

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

HEADER = codexion.h

SRC = main.c\
      parser.c\
      dongles.c\
      coders.c\
      simulation.c\
      routine.c\
      utils.c

OBJS = $(SRC:.c=.o)

ARGS = 5 800 200 200 200 2 100 fifo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME) $(ARGS)

helgrind: $(NAME)
	valgrind --tool=helgrind ./$(NAME) $(ARGS)

leak_check: $(NAME)
	valgrind --leak-check=full ./$(NAME) $(ARGS)

.PHONY: all clean fclean re test helgrind leak_check
