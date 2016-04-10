NAME = libftprintf.a

SRC_PATH = ./sources

SRC_NAME = ft_printf.c printf_fct.c

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
	norminette $(SRC)

test: all
	$(CC) -o test main.c $(NAME)
