CC					= cc
RM					= rm -f
CFLAGS				= -Wextra -Wall -Werror -g3
MLX_PATH			= ./mlx/
LIBFT_PATH 			= ./libft/
LDFLAGS				= -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -I$(INCLUDE_PATH) -I$(MLX_PATH) -lXext -lX11
INCLUDE_PATH 		= ./includes/
CUB3DNAME 			= cub3d
CUB3DSRCS			= ./sources/main.c \
                  ./sources/exec/init_game.c \
                  ./sources/exec/player.c \
                  ./sources/exec/utils.c \
				  ./sources/exec/movements.c \
				  ./sources/exec/keyhooks.c \
				  ./sources/exec/raycasting.c
CUB3DOBJS 			= $(CUB3DSRCS:.c=.o)

LIBFT 				= $(LIBFT_PATH)libft.a
MLX					= $(MLX_PATH)libmlx.a

all:				$(CUB3DNAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -c $< -o $@

$(CUB3DNAME):	$(CUB3DOBJS) $(LIBFT) $(MLX)
				$(CC) -o $(CUB3DNAME) $(CUB3DOBJS) $(CFLAGS) $(LDFLAGS) -lm

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MLX):	
				$(MAKE) -C $(MLX_PATH)

clean:
				$(RM) $(CUB3DOBJS)
				@$(MAKE) -C $(LIBFT_PATH) clean
				@$(MAKE) -C $(MLX_PATH) clean

fclean:	 		clean
				$(RM) $(CUB3DNAME)
				@$(MAKE) -C $(LIBFT_PATH) fclean

re:				fclean
				$(MAKE) all

.PHONY:			all clean fclean re