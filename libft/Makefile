NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalnum.c \
ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memmove.c \
ft_strdup.c ft_strnstr.c ft_isascii.c ft_memset.c ft_striteri.c \
ft_strrchr.c ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
ft_write.c ft_putnbr.c ft_printf.c ft_print_ptr.c ft_print_base.c\
get_next_line.c

OBJDIR = objs/

OBJ = $(addprefix ${OBJDIR}, $(SRC:.c=.o))

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJ = $(addprefix ${OBJDIR}, $(BONUS:.c=.o))

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $@ $?

${OBJDIR}%.o:%.c
	@mkdir -p ${@D}
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

bonus: $(OBJ) $(BONUS_OBJ)
	@ar rcs ${NAME} $?

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus
