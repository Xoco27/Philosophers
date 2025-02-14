PRINTF =	ft_printf.c ft_printstring.c ft_printint.c ft_printuns.c ft_printptr.c ft_printhex.c

POBJ = $(PRINTF:.c=.o)

NAME = libftprintf.a

CC = cc

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(POBJ)
			ar rsc $@ $(POBJ)

all:		$(NAME)

clean:
			rm -f $(POBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
