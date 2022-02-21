# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 14:07:04 by ytouate           #+#    #+#              #
#    Updated: 2022/02/21 15:11:23 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
CFLAGS = -Wall -Werror -Wextra

SRC_PART1 =	\
	./push_swap.c			\
	./libft_utils.c			\
	./sorting_funcs.c		\
	./stack_adt.c 			\
	./stack_manipulation.c	\
	./valid_stack.c			\
	./sorting_utils.c		\

BONUS = \
	./stack_manipulation.c	\
	./checker.c				\
	./checker_utils.c		\
	./get_next_line.c		\
	./get_next_line_utils.c	\
	./libft_utils.c			\
	./valid_stack.c			\
	./stack_adt.c 			\
	./valid_instractions.c	\
	./sorting_utils.c		\

PARTS = $(BONUS) $(SRC_PART1)

OBJS = $(PARTS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rc push_swap.a $(OBJS)
	@$(CC) $(CFLAGS) push_swap.c push_swap.a -o $(NAME)

clean :
	@rm -f $(OBJS) 

fclean : clean
	@rm -f push_swap $(NAME) checker push_swap.a

re : fclean all

OBBS = $(BONUS:.c=.o)

$(B_NAME) : $(OBBS)
	ar -rc push_swap.a $(OBBS)
	@$(CC) $(CFLAGS) checker.c push_swap.a -o $(B_NAME)
bonus : $(B_NAME)

.PHONY : all clean fclean re bonus