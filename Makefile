CC = cc

NAME = libbuiltins.a

CFLAGS = -Wall -Wextra -Werror -I../libft # -g -ggdb3 -fsanitize=address

M_SRC = minishell.c builtin_utils.c builtins.c lst_operations.c utils.c

M_HEAD = $(M_SRC:.c=.h)

M_OBJ = $(M_SRC:.c=.o)

LIBFT = libft

all: $(NAME)

$(NAME): rf_lib $(M_OBJ) # $(LIBFT)/libft.a
	ar rcs $@ $(M_OBJ)
#$(NAME):
#	$(CC) $(CFLAGS) $(M_OBJ) $(LIBFT)/libft.a -o $(NAME)

#$(LIBFT)/libft.a:
#	make -C $(LIBFT) all

%.o : %.c $(M_HEAD) # TODO : add minishell.c here
	$(CC) $(CFLAGS) -c $< -o $@
rf_lib:
	rm -f $(NAME)
clean:
	rm -rf $(M_OBJ)
#	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
#	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus
