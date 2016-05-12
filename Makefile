NAME = libftprintf.a

SRC_PATH = ./sources

SRC_NAME = ft_printf.c nbr_fct.c data.c parse_flags.c list_fct.c\
 						mask.c lst_print.c formatage.c long_char.c oct_hex.c\
						str_char.c longlong.c short.c fct_init.c short2.c\
						formatage2.c lst_print2.c lst_print3.c mwidth.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(SRC:.c=.o)

LIB = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I./includes -I./libft/includes

all: $(NAME)

$(LIB):
	make -C ./libft
	cp ./libft/libft.a libft.a

$(NAME): $(OBJ) $(LIB)
	mv $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C ./libft
	rm -fv $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

norme:
	norminette $(SRC) includes/ft_printf.h

test: all
	$(CC) -o test main.c $(NAME)
	./test
