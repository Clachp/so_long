NAME=	so_long

CC=		gcc

SRCS=	minitest.c

OBJ=	$(SRCS:.c=.o)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@echo "So long Marianne... Run it !"
	@$(CC) -o $(NAME) $(OBJ) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 

all : $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all