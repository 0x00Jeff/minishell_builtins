CC = cc

NAME = libbuiltins.a

EXEC = minishell

CFLAGS = -Wall -Wextra -Werror -I../../include -g -ggdb3 -fsanitize=address

M_SRC = minishell.c builtin_utils.c builtins.c lst_operations.c utils.c

EXEC_SRC = main.c $(M_SRC)

M_HEAD = $(M_SRC:.c=.h)

M_OBJ = $(M_SRC:.c=.o)
EXEC_OBJ = main.o $(M_SRC:.c=.o)

LIBFT = ../libft

all: $(NAME)

$(NAME): rf_lib $(M_OBJ)
	ar rcs $@ $(M_OBJ)
exec:	$(EXEC_OBJ) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(EXEC_OBJ) $(LIBFT)/libft.a -o $(EXEC)

$(LIBFT)/libft.a:
	make -C $(LIBFT) all

%.o : %.c $(M_HEAD) # TODO : add minishell.c here
	$(CC) $(CFLAGS) -c $< -o $@
rf_lib:
	rm -f $(NAME)
clean:
	rm -rf $(M_OBJ)
exec_clean:
	make -C $(LIBFT) clean
	rm -rf $(EXEC_OBJ)

fclean: clean
	rm -rf $(NAME)
exec_fclean: exec_clean
	rm -rf $(EXEC)
	rm -rf $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re bonus
