CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = cub3d
C_FILES = source/main.c source/game/run_game.c source/game/image/create_image.c source/game/image/put_pixel_into_image.c \
			source/parsing/error_checks.c
H_FILES = source/cub3d.h source/game/image/image.h
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

