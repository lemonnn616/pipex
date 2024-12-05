NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc
FLAGS = -O3 -g3 -L -lft
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft
LIBS = /include

RM = rm -f
FILES = pipex.c pipex_utils.c

FILES_BONUS = pipex_bonus.c pipex_utils_bonus.c pipex_here_doc_bonus.c pipex_piping_bonus.c

OBJ_DIR = build

OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I.$(LIBS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT)
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(LIBFT)/libft.a $(FLAGS) -o $(NAME_BONUS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus