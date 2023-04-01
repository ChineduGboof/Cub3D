CC = gcc -g
FLAGS = -Wall -Wextra - Werror
NAME = cub3d

C_FILES = source/main.c source/game/run_game.c source/game/image/image_factory.c \
source/game/image/put_pixel_into_image.c source/game/raycasting/orchestra_conductor.c \
source/game/raycasting/drawing.c source/game/raycasting/grid_step_calculations.c \
source/game/raycasting/ray_direction_calculations.c source/game/raycasting/texture_handling.c \
source/game/raycasting/wall_detection.c source/game/raycasting/vector_manipulation.c \
source/game/event_handlers.c source/game/textures.c source/game/image/color.c \
source/game/image/paint.c source/game/safe_termination.c source/game/map_utilities/convert_map.c \
source/game/map_utilities/map_interpretation.c source/game/map_utilities/int_map_utilities.c \
source/game/display.c source/game/player_actions.c source/parsing/error_checks.c \
source/parsing/parsing_utils.c source/parsing/parse_colors.c source/parsing/parse_textures.c \
source/parsing/parse_map.c source/parsing/validate_map.c source/parsing/parsing_utils2.c \
source/parsing/parsing.c source/parsing/parse_colors2.c source/parsing/validate_args.c \
source/parsing/parse_textures2.c source/parsing/parse_map2.c source/parsing/validate_map2.c

H_FILES = source/cub3d.h source/game/image/image.h source/game/game.h source/game/raycasting/raycasting_local.h

O_FILES = $(subst .c,.o,${C_FILES})
LIBFT = libraries/libft/libft.a
MINILIBX = libraries/minilibx/libmlx.a
STATIC_LIBRARIES = ${LIBFT}

all: ${NAME}

$(NAME) : $(O_FILES) ${LIBFT} ${MINILIBX}
	${CC}  ${FLAGS} ${O_FILES} ${STATIC_LIBRARIES} -L libraries/minilibx -l mlx -framework OpenGL -framework AppKit -o ${NAME}

%.o : %.c ${H_FILES} ${LIBFT} ${MINILIBX}
	${CC}  -I libraries/minilibx -I libraries/libft ${FLAGS} -c $< -o $@

${MINILIBX}:
	cd libraries/minilibx && make
${LIBFT}:
	cd libraries/libft && make

clean:
	rm -f ${O_FILES} && cd libraries/libft && make clean

fclean: 
	rm -f ${O_FILES} && rm -f ${NAME} && cd libraries/minilibx && make clean && cd ../libft && make fclean

re: fclean all

