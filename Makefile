CC = cc

NAME = minishell

CFLAGS = -Wall -Wextra -Werror

M_SRC = minishell.c builtin_utils.c builtins.c

M_OBJ = $(M_SRC:.c=.o)

LIBFT = libft

all: $(NAME)

$(NAME): $(M_OBJ) $(LIBFT)/libft.a
	$(CC) $(M_OBJ) $(LIBFT)/libft.a -o $(NAME)

$(LIBFT)/libft.a:
	make -C $(LIBFT) all

%.o : %.c # TODO : add minishell.c here
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(M_OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus
