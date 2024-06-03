NAME = libft.a
SOURCES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	  ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memmove.c ft_memset.c ft_atoi.c ft_strchr.c ft_strlen.c \
	  ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c \
	  ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
	  ft_toupper.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

BLUE := \033[0;34m
PINK := \033[1;35m
BLUE2 := \033[0;36m

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) -rcs $@ $^
	@echo "$(BLUE)COMPILATION DONE"
so:
	gcc *.o --shared -o libft.so


%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJECTS)
	@echo "$(BLUE2)CLEAN ALL THE OBJ"

fclean: clean
	@rm -f $(NAME)
	@echo "$(PINK)CLEAN EVERYTHING"

re: fclean all

.PHONY: all clean fclean re so
