# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 15:15:55 by mchiboub          #+#    #+#              #
#    Updated: 2023/06/18 17:40:44 by mchiboub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PRINTF = printf
PRINTF_LIB = libftprintf.a

SRCS =	push_swap.c		\
		utils.c			\
		read_inputs.c	\
		check_stacks.c	\
		print_stacks.c	\
		op_stack_a.c	\
		op_stack_b.c	\
		op_stacks.c		\
		algo_3_elems.c	\
		algo_5_elems.c	\
		algo_v2.c		\
		algo_v2_a.c		\
		algo_v2_b.c		\
		algo_v2_c.c		\
		init_stacks.c

SRCS_BONUS = 	checker.c		\
				init_stacks.c	\
				print_stacks.c	\
				utils.c			\
				check_stacks.c	\
				read_inputs.c	\
				op_stack_a.c	\
				op_stack_b.c	\
				op_stacks.c		\
				algo_3_elems.c	\
				algo_5_elems.c	\
				algo_v2.c		\
				algo_v2_a.c		\
				algo_v2_b.c		\
				algo_v2_c.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

GREEN = \033[0;32m
NC = \033[0m

all: ${NAME}

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -lreadline

${NAME}: ${OBJS}
		@echo "Generating ${GREEN}${NAME}${NC} executable.."
		@make -sC ${PRINTF} all
		@${CC} -o ${NAME} ${OBJS} ${PRINTF}/${PRINTF_LIB} -lreadline

bonus: ${OBJS_BONUS}
		@echo "Generating ${GREEN}${NAME_BONUS}${NC} executable.."
		@make -sC ${PRINTF} all
		@${CC} -o ${NAME_BONUS} ${OBJS_BONUS} ${PRINTF}/${PRINTF_LIB} -lreadline

clean:
		@echo "Deleting object files.."
		@rm -f ${OBJS} ${OBJS_BONUS}
		@make -sC ${PRINTF} clean

fclean: clean
		@echo "Deleting object & executable files.."
		@rm -f ${NAME} ${NAME_BONUS}
		@make -sC ${PRINTF} fclean

re: fclean all
