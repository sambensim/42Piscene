CC = cc $(FLAGS) 

CFLAGS = -Wall -Werror -Wextra

NAME = bsq

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f *.o
	rm -f bsq

fclean: clean
	rm -f *~ *.h.gch
