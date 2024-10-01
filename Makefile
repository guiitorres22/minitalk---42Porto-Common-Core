# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 22:18:22 by gtinani-          #+#    #+#              #
#    Updated: 2024/10/01 21:03:16 by gtinani-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc -g
NAMEC = client
NAMES = server
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRCS = client.c 
SRSS = server.c

all:	${NAMEC} ${NAMES}

${LIBFT}:
	@make -C Libft
${PRINTF}:
	@make -C Printf
${NAMEC}: ${LIBFT} ${PRINTF}
	@${CC} ${SRCS} ${LIBFT} ${PRINTF} ${FLAGS} -o ${NAMEC}
${NAMES}: ${LIBFT} ${PRINTF}
	${CC} ${SRSS} ${LIBFT} ${PRINTF} ${FLAGS} -o ${NAMES}
clean:
	@rm ${NAMEC}
	@rm ${NAMES}
	@echo ALL CLEAR
re: clean all