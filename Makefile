NAME=		solong

CC=			gcc

FLAGS=		-Wall -Wextra -Werror -g	

SRCS=		window.c

OBJ_DIR=	obj

OBJ=		$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@echo "So long Marianne... Run it !"
	@$(CC) -o $(NAME) $(OBJ) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 

all : $(NAME)

clean :
	@rm -rf $(OBJ_DIR)/

fclean : clean
	@rm -rf $(NAME)

re : fclean all
