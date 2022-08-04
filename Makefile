NAME=		solong

CC=			gcc

CFLAGS=		-g3 -Wall -Wextra -Werror

RM=			rm -rf

SRCS=		main.c \
			check_utils.c \
			load_images.c \
			check_map.c \
			init_map.c \
			interactions.c \
			clean_game.c

OBJ_DIR=	obj

OBJ=		$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I. -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(OBJ)
	@make --no-print-directory -C libft
	@echo "So long, Marianne"
	@$(CC) -g3 -o $(NAME) $(OBJ) -I. -Imlx -Llibft -lft -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 

all : $(NAME)

clean :
	@make --no-print-directory fclean -C libft
	@$(RM) $(OBJ_DIR)/

fclean : clean
	@$(RM) $(NAME)

re : fclean
	@make --no-print-directory all

PHONY : all clean fclean re
