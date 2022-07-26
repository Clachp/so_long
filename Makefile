NAME=		solong

CC=			gcc

CFLAGS=		-g3 -Wall -Wextra -Werror
RM=			rm -rf
SRCS=		main.c map.c

OBJ_DIR=	obj

OBJ=		$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I. -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(OBJ)
#	make -C $(MLX)
	@make -C libft
	@echo "So long, Marianne"
	@$(CC) -g3 -fsanitize=address -o $(NAME) $(OBJ) -I. -Imlx -Llibft -lft -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 

all : $(NAME)

clean :
	@make fclean -C libft
	@$(RM) $(OBJ_DIR)/

fclean : clean
	@$(RM) $(NAME)

re : fclean all

PHONY : all clean fclean re
