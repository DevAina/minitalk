NAME_CLIENT = client

NAME_SERVER = server

LIBFTPRINTF = ./ft_printf/libftprintf.a

SRC_CLIENT = ./srcs/client.c

SRC_SERVER = ./srcs/server.c

SRC_BONUS_CLIENT = ./bonus/client_bonus.c

SRC_BONUS_SERVER = ./bonus/server_bonus.c

FLAGS = -Wall -Werror -Wextra

CC = cc

OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

OBJ_BONUS_CLIENT = ${SRC_BONUS_CLIENT:.c=.o}

OBJ_SERVER = ${SRC_SERVER:.c=.o}

OBJ_BONUS_SERVER = ${SRC_BONUS_SERVER:.c=.o}

all: ${LIBFTPRINTF} ${NAME_CLIENT} ${NAME_SERVER}

bonus: ${LIBFTPRINTF} ${NAME_CLIENT}_bonus ${NAME_SERVER}_bonus

.c.o:
	cc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

${LIBFTPRINTF}:
	make -C ft_printf

${NAME_CLIENT}: ${OBJ_CLIENT}
	${CC} ${FLAGS} -o client ${OBJ_CLIENT} -L./ft_printf -lftprintf

${NAME_SERVER}: ${OBJ_SERVER}
	${CC} ${FLAGS} -o server ${OBJ_SERVER} -L./ft_printf -lftprintf

${NAME_CLIENT}_bonus: ${OBJ_BONUS_CLIENT}
	${CC} ${FLAGS} -o ${NAME_CLIENT} ${OBJ_BONUS_CLIENT} -L./ft_printf -lftprintf

${NAME_SERVER}_bonus: ${OBJ_BONUS_SERVER}
	${CC} ${FLAGS} -o ${NAME_SERVER} ${OBJ_BONUS_SERVER} -L./ft_printf -lftprintf

clean:
	make fclean -C ./ft_printf
	rm -f ${OBJ_CLIENT} ${OBJ_SERVER} ${OBJ_BONUS_CLIENT} ${OBJ_BONUS_SERVER}

fclean: clean
	make clean -C ./ft_printf
	rm -f ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all
