NAME = libft.a

NAME_BONUS = libft_bonus

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_cautious_free.c ft_free_2d_array.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_split_charset.c ft_strchr.c \
	ft_strcmp.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strrncmp.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_isnumeric.c ft_atol.c ft_countwords.c \
	${GNL_SRC}

GNL_SRC = ${addprefix get_next_line/, get_next_line.c get_next_line_utils.c}

SRC_BNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c

OBJ = ${SRC:c=o}
OBJ_BNS =${SRC_BNS:c=o}

${NAME} : ${OBJ}
	@ar -rcs libft.a ${OBJ}

%.o : %.c
	@${CC} -c ${CFLAGS} $< -o $@

clean:
	@${RM} ${OBJ} ${OBJ_BNS}

fclean: clean
	@${RM} ${NAME}

all: ${NAME}

re: fclean all

bonus: ${OBJ} ${OBJ_BNS}
	@ar -rcs libft.a ${OBJ} ${OBJ_BNS}
