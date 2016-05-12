NAME = libft.a 

SRCS =	ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lststrsplit.c\
		ft_lstprint.c\
		ft_lstaddend.c\
		ft_lstdelfirst.c\
		ft_lstdellast.c\
		ft_lstfold.c\
		ft_lstdelcmp.c\
		ft_strndup.c\
		ft_strend.c\
		ft_strend.c\
		ft_pow.c\
		ft_itoa_base.c\
		ft_uitoa_base.c\
		ft_ulpow.c\
		ft_litoa_base.c\
		ft_uitoa_basemaj.c\
		ft_atoi_base.c\
		get_next_line.c\
		ft_putnbendl.c

OBJS = $(SRCS:.c=.o)

.PHONY: all, clean, fclean, re

all : $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc -c -Wall -Wextra -Werror -Iincludes $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

test : 
	gcc -Wall -Wextra -Werror $(SRCS) test_ft.c

norm :
	norminette $(SRCS) libft.h

maintest : all
	gcc main.c -I. libft.a 


