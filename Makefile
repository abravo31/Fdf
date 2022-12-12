MLX_LINUX_PATH	=	./minilibx-linux
MLX_LINUX		=	$(MLX_LINUX_PATH)/libmlx.a

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	main.c \
					check_file.c read_map.c draw_map.c img.c utils.c tools_z.c

BONUS_FILES	=	main_bonus.c \
					check_file_bonus.c read_map_bonus.c draw_map_bonus.c \
					img_bonus.c utils_bonus.c tools_z_bonus.c color.c

SOURCES_DIR		=	srcs

SRC_DIR_BONUS	=	src_bonus

HEADER			=	$(SOURCES_DIR)/fdf.h

HERDER_BONUS	=	$(SRC_DIR_BONUS) $(SOURCES_DIR)/fdf.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

SRC_BONUS		=	$(addprefix $(SRC_DIR_BONUS)/, $(BONUS_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

OBJ_BONUS		= 	$(SRC_BONUS:.c=.o)

MAKE			=	make

NAME			=	fdf

NAME_BONUS		=	fdf_bonus

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-g3 -Wall -Wextra -Werror #-fsanitize=address
MLX_LINUX_FLAGS	=	-L. -lXext -L. -lX11 -lm -lbsd

all:	$(NAME)

.c.o:		
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


$(NAME):	$(MLX_LINUX) $(OBJECTS) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(HEADER) $(LIBFT) $(MLX_LINUX) $(MLX_LINUX_FLAGS) 
	@echo "\033[32m$ ${NAME} compiled !"
	@echo "----------------------------\033[0m"

$(MLX_LINUX):
	$(MAKE) -C $(MLX_LINUX_PATH)
	@echo "\033[32m$ minilibx compiled !"
	@echo "----------------------------\033[0m"

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	@echo "\033[32m$ libft compiled !"
	@echo "----------------------------\033[0m"

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(MLX_LINUX) $(OBJ_BONUS) $(HEADER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(HEADER_BONUS) $(LIBFT) $(MLX_LINUX) $(MLX_LINUX_FLAGS)
	@echo "\033[32m$ ${NAME_BONUS} compiled !"
	@echo "----------------------------\033[0m"

clean:
	@$(MAKE) -C $(MLX_LINUX_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJECTS) $(OBJ_BONUS)
	@echo "\033[32mClean !\033[0m"

fclean:		clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re minilibx bonus
