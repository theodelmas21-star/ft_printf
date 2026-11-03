NAME = libftprintf.a

CC = cc

MY_SOURCES =	ft_printf.c \
				ft_strlen.c \
				ft_putchar_count.c \
				ft_putstr.c \
				ft_hexa.c \
				ft_unsigned_decimal.c \
				ft_num_hexa.c \
				ft_putnbr.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

%.o: %.c
	 $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

compile : $(MY_SOURCES)
		$(CC) $(CFLAGS) $(MY_SOURCES)

all: $(NAME)

cleana :
	rm -f a.out
clean:
		rm -f $(MY_OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all