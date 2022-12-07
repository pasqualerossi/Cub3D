NAME := cub3d

CC := gcc

CFLAGS := -Wall -Wextra -Werror -D BUFFER_SIZE=100

GAME_LOGIC := game_logic/*.c
GAME_MAP := game_logic/game_map/*.c
GAME_PLAYER := game_logic/game_player/*.c
GAME_UTILS := game_logic/game_utils/*.c

LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(GAME_LOGIC) $(GAME_MAP) $(GAME_PLAYER) $(GAME_UTILS) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all