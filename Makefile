# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 14:07:04 by ytouate           #+#    #+#              #
#    Updated: 2022/02/21 12:16:26 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

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
	

PARTS = $(BONUS) $(SRC_PART1)

OBJS = $(PARTS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) push_swap.c $(NAME) -o push_swap

clean :
	@rm -f $(OBJS) 

fclean : clean
	@rm -f push_swap $(NAME) checker

re : fclean all

OBBS = $(BONUS:.c=.o)

bonus : $(OBBS)
	@ar -rc $(NAME) $(OBBS)
	@$(CC) $(CFLAGS) checker.c $(NAME) -o checker
.PHONY : all clean fclean re bonus