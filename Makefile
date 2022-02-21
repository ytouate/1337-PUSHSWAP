# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 14:07:04 by ytouate           #+#    #+#              #
#    Updated: 2022/02/21 10:15:27 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CFLAGS = -Wall -Werror -Wextra

SRC_PART1 =	\
	./push_swap.c			\
	./libft_utils.c			\
	./sorting_funcs.c		\
	./stack_adt.c 			\
	./stack_manipulation.c	\
	./valid_stack.c			\
	./sorting_utils.c		\


PARTS = $(SRC_PART1)

OBJS = $(PARTS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) push_swap.c $(NAME) -o push_swap

clean :
	@rm -f $(OBJS) $(NAME)

fclean : clean
	@rm -f push_swap

re : fclean all

.PHONY : all clean fclean re bonus