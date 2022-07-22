NAME=	libs.a

CC=		gcc

CLFAGS=		-Wall -Wextra -Werror

LIBFT=

FT_PRINTF=

GNL=

all: $(NAME)

$(NAME): libft ft_printf gnl

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	$(AR) $(ARFLAGS) $(NAME) $@

libft: $(addprefix libft/, $(LIBFT:.c=.o))
ft_printf: $(addprefix ft_printf/, $(FT_PRINTF:.c=.o))
gnl: $(addprefix gnl/, $(GNL:.c=.o))

clean:
	rm -rf $(addprefix libft/, $(LIBFT:.c=.o))
	rm -rf $(addprefix ft_printf/, $(FT_PRINTF:.c=.o))
	rm -rf $(addprefix gnl/, $(GNL:.c=.o))

fclean: clean
	rm -rf $(NAME)

re: fclean all

