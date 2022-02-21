/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:38:19 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/21 10:09:16 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <signal.h>

typedef struct s_stack
{
	int				val;
	int				index;
	struct s_stack	*next;
}t_stack;
void	swap2(t_stack **a);
void	insert2(t_stack **a, t_stack **b);
void	rotate2(t_stack	**a);
void	reverse_rotate(t_stack **a, char c);
void	combine(t_stack **a, t_stack **b, char *arg);
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
void	sort_three_ints(t_stack **a, char c);
void	insert(t_stack **a, t_stack **b, char c);
void	sort_five(t_stack **a, t_stack **b);
void	check_args(int ac, char **av);
void	sort(t_stack **a, t_stack **b, const char c);
int		*insert_array(t_stack *a);
int		pop(t_stack **a);
int		stack_is_empty(t_stack *a);
int		stack_len(t_stack *a);
int		ft_atoi(const char *str);
int		is_sorted(t_stack *a);
int		get_min(t_stack *a);
int		get_max(t_stack *a);
int		stack_min(t_stack *a);
int		get_index(t_stack *a, int val);
int		stack_top(t_stack *a);
int		ft_strcmp(char *str, char *s);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strchr(const char *s, int c);
void	fill_stack(int ac, char **av, t_stack **a);
void	change(int *x, int *y);
#endif