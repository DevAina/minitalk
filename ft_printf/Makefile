# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trarijam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 15:08:07 by trarijam          #+#    #+#              #
#    Updated: 2024/04/03 15:29:20 by trarijam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

LIBFT_LIB_A = libft.a

SRCS = mandatory/fc_print.c mandatory/ft_printf.c mandatory/ft_printf_utils.c mandatory/fc_utils_for_print.c

SRCS_BONUS = bonus/fc_flags.c bonus/fc_print_char_and_str.c bonus/ft_printf_bonus.c \
				bonus/ft_printf_utils_bonus.c bonus/print_digit_hexa.c \
				bonus/print_digit_with_flags.c bonus/print_ptrvoid_with_flags.c \
				bonus/print_unsigned_with_flags.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	cp ${LIBFT}/${LIBFT_LIB_A} ${NAME}
	ar rc ${NAME} ${OBJS}

bonus: ${OBJS_BONUS}
	make -C ${LIBFT}
	cp ${LIBFT}/${LIBFT_LIB_A} ${NAME}
	ar rc ${NAME} ${OBJS_BONUS}

clean:
	make clean -C ${LIBFT}
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	make fclean -C ${LIBFT}
	rm -f ${NAME}

re:fclean all

.PHONY: all clean fclean re bonus
