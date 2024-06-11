NAME = minitalk

NAME_CLIENT = client

NAME_SERVER = server

LIBFTPRINTF = ./ft_printf/libftprint.a

SRC_CLIENT = ./srcs/client.c

SRC_CLIENT_BONUS = ./bonus/client_bonus.c

SRC_SERVER_BONUS = ./bonus/server_bonus.c

SRC_SERVER = ./srcs/server.c

OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

OBJ_CLIENT_BONUS = ${SRC_CLIENT_BONUS:.c=.o}

OBJ_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}

OBJ_SERVER = ${SRC_SERVER:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = cc

all: ${NAME}

${NAME}: ${NAME_CLIENT} ${NAME_SERVER}

bonus: ${NAME_CLIENT}_bonus ${NAME_SERVER}_bonus

.c.o:
	${CC} -g ${FLAGS} -c $< -o ${<:.c=.o}

${NAME_CLIENT}: ${OBJ_CLIENT}
	make -C ./ft_printf
	${CC} ${FLAGS} -o ${NAME_CLIENT} ${OBJ_CLIENT} -L./ft_printf -lftprintf

${NAME_SERVER}: ${OBJ_SERVER}
	make -C ./ft_printf
	${CC} ${FLAGS} -o ${NAME_SERVER} ${OBJ_SERVER} -L./ft_printf -lftprintf

${NAME_CLIENT}_bonus: ${OBJ_CLIENT_BONUS}
	make -C ./ft_printf
	${CC} ${FLAGS} -o ${NAME_CLIENT} ${OBJ_CLIENT_BONUS} -L./ft_printf -lftprintf

${NAME_SERVER}_bonus: ${OBJ_SERVER_BONUS}
	make -C ./ft_printf
	${CC} ${FLAGS} -o ${NAME_SERVER} ${OBJ_SERVER_BONUS} -L./ft_printf -lftprintf

clean:
	make clean -C ./ft_printf
	rm -f ${OBJ_CLIENT} ${OBJ_SERVER} ${OBJ_CLIENT_BONUS} ${OBJ_SERVER_BONUS}

fclean: clean
	make fclean -C ./ft_printf
	rm -f ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all
