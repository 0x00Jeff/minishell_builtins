CC = cc

NAME = libbuiltins.a

EXEC = minishell

CFLAGS = -Wall -Wextra -Werror -I../../include -g -ggdb3 -fsanitize=address

ECHO	= echo/echo.c echo/utils.c
CD	= cd/cd.c cd/utils.c
EXIT	= exit/exit.c exit/utils.c
PWD	= pwd/pwd.c pwd/utils.c
UNSET	= unset/unset.c unset/utils.c
EXPORT	= export/export.c export/utils.c
ENV	= env/env.c env/utils.c

M_SRC = $(ECHO) $(CD) $(EXIT) $(PWD) $(UNSET) $(EXPORT) $(ENV) global_utils.c builtin_dispatcher.c lst_operations.c

EXEC_SRC = main.c $(M_SRC)

M_HEAD = global_utils.h builtins_dispatcher.h lst_operations.h exit/utils.h pwd/utils.h unset/utils.h export/utils.h env/utils.h lst_operations.h global_utils.h

M_OBJ = $(M_SRC:.c=.o)
EXEC_OBJ = main.o $(M_SRC:.c=.o)

LIBFT = ../libft

all: $(NAME) clean

$(NAME): rf_lib $(M_OBJ)
	ar rcs $@ $(M_OBJ)

exec:	$(EXEC_OBJ) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(EXEC_OBJ) $(LIBFT)/libft.a -o $(EXEC)

cp: $(NAME)
	cp -rfv * ../1337/minishell-1337/src/minishell_builtins/

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
