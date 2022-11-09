MLX_LINUX_PATH	=	./minilibx-linux
MLX_LINUX		=	$(MLX_LINUX_PATH)/libmlx.a

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	main.c \
					check_file.c read_map.c

SOURCES_DIR		=	srcs

HEADER			=	$(SOURCES_DIR)/fdf.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

MAKE			=	make

NAME			=	fdf

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-g3 -Wall -Wextra -Werror -D BUFFER_SIZE=100
MLX_LINUX_FLAGS	=	-L. -lXext -L. -lX11 -lm -lbsd

.c.o:		
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(MLX_LINUX) $(OBJECTS) $(HEADER) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(HEADER) $(LIBFT) $(MLX_LINUX) $(MLX_LINUX_FLAGS) -o $(NAME)
	@echo "\033[32m$ ${NAME} compiled !"
	@echo "----------------------------\033[0m"

$(MLX_LINUX):
	@$(MAKE) -C $(MLX_LINUX_PATH)
	@echo "\033[32m$ minilibx compiled !"
	@echo "----------------------------\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "\033[32m$ libft compiled !"
	@echo "----------------------------\033[0m"

clean:
	@$(MAKE) -C $(MLX_LINUX_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJECTS)
	@echo "\033[32mClean !\033[0m"

fclean:		clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re minilibx
