SRC = $(shell find src -name "*.c")
OBJS = $(SRC:.c=.o)
NAME = libft.a
FLAGS = -c -Wall -Werror -Wextra -I
all: $(NAME)
$(NAME): $(OBJS)
    ar rcs $(NAME) $(OBJS)
.c.o:
    gcc $(FLAGS) includes $< -o $@
clean:
    rm -f src/*.o
fclean: clean
    rm -f libft.a
re: fclean all
.PHONY: clean fclean re all