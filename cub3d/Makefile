CC = gcc
FLAGS = -Wall -Wextra
NAME = cub3d
C_FILES = source/main.c source/run_game.c
H_FILES = 
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

