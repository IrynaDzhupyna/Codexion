NAME = codexion

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

HEADER = codexion.h

SRC = main.c\
      parser.c\
      coders.c\
      dongles.c\
      print.c

OBJS = $(SRC:.c=.o)

ARGS = 2 200 200 200 200 2 100 fifo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re test
