NAME = push_swap

RM = rm -rf
CC = clang
CFLAGS = -Wall -Werror -Wextra 
SRC = push_swap.c\
	  push_swap_quicksort.c\
	  push_swap_push.c\
	  push_swap_utils.c\
	  push_swap_moves1.c\
	  push_swap_moves2.c\
	  push_swap_moves3.c\

LIB_A = libft/libft.a



$(NAME): $(SRC) $(LIB_A)
	$(CC) $(CFLAGS) $(SRC) $(LIB_A) -o $(NAME)

$(LIB_A): libft/*.c
	$(MAKE) -C libft/
	$(MAKE) -C libft/ bonus


all: $(NAME)

re: fclean all

clean :
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) libft/libft.a
	$(RM) $(NAME) $(LIB_A)

.PHONY: all re clean fclean

