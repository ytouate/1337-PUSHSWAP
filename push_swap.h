/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:38:19 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/09 10:33:18 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    int val;
    struct s_stack *next;
}t_stack;
size_t	ft_strlen(const char *s);
void	push(t_stack **a, int val);
void	swap(t_stack **a, char c);
void	insert(t_stack **a, t_stack **b, char c);
void	swap_a_b(t_stack **a, t_stack **b);
void	rotate(t_stack	**a, char c);
void	rotate_a_b(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **a, char c);
void	rrr(t_stack **a, t_stack **b);
void	display_stack(t_stack *a);
void	check_dup(int *arr, int size, int val);
void	sort_descending(t_stack **a, t_stack **b);
void	check_args(char **av);
void	sort_three_ints(t_stack **a, char c);
void	insert(t_stack **a, t_stack **b, char c);
int		pop(t_stack **a);
int		peek(t_stack *a, int pos);
int		stack_top(t_stack *a);
int		stack_is_empty(t_stack *a);
int		stack_len(t_stack *a);
int		ft_atoi(const char *str);
int		is_descending(t_stack *a);
char	**ft_split(char const *s, char c);


#endif