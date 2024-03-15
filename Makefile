NAME = libftprintf.a

SRC = ft_printchar.c ft_printdecimalint.c ft_printf.c \
      ft_printhexa.c ft_printstr.c ft_printptr.c \
      ft_printunsigned.c \

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) -rcs $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
