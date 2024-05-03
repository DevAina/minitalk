NAME_CLIENT = client

NAME_SERVER = server

PRINTF = libftprint.a

SRC_CLIENT = srcs/client.c

SRC_SERVER = srcs/server.c

OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

OBJ_SERVER = ${SRC_SERVER:.c=.o}

all: ${PRINTF} ${NAME_CLIENT} ${NAME_SERVER}

.c.o:
	cc -Wall -Werror -Wextra -c< -o ${<:.c=.o}

${PRINTF}:
	make -C ft_printf
    cp ft_printf/${PRINTF} ${PRINTF}
 
${NAME_CLIENT}: ${OBJ_CLIENT}
	ar rc ${NAME_CLIENT}.a ${OBJ_CLIENT}

${NAME_SERVER}: ${OBJ_SERVER}
    ar rc ${NAME_SERVER}.a ${OBJ_SERVER}



