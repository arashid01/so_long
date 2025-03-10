NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS =  srcs/so_long.c srcs/read_map.c srcs/clean_utils.c \
		srcs/initialize_game.c srcs/render_map.c srcs/map_validation.c \
		srcs/map_validation_utils.c srcs/player_movement.c  srcs/count_collectibles.c \
		srcs/path_validation.c srcs/load_images.c srcs/exit_func.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = includes/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = ../minilibx-linux
MLX = $(MLX_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft \
		-L$(FT_PRINTF_DIR) -lftprintf \
		$(MLX_FLAGS) -o $(NAME)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
