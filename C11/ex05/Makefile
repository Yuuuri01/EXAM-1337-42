CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC := ft_atoi.c ft_putnbr.c do_op.c
OBJ := $(SRC:.c=.o)
NAME = do_op
RM = rm -f


.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJ)
fclean : clean
	@$(RM) $(NAME);
re : fclean all;