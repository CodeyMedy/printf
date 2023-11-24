SRCS = ft_printf.c ft_printf_formatters.c ft_printf_utils.c ft_printf_chars.c ft_printf_hexa.c ft_printf_ptr.c  ft_printf_nums.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = cc
AR = ar rcs
INC = ft_printf.h
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	$(AR) $(NAME) $(OBJS) $(INC)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@ -I.

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re