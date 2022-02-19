/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:48:51 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/19 20:47:55 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a, char c)
{
	int	x;
	int	y;

	if (stack_len(*a) < 2 || !*a)
		return ;
	x = stack_top(*a);
	pop(a);
	y = stack_top(*a);
	pop(a);
	push(a, x);
	push(a, y);
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 's')
		return ;
	else
		write(1, "sb\n", 3);
}

void	insert(t_stack **a, t_stack **b, const char c)
{
	int	x;

	if (!*b)
		return ;
	x = stack_top(*b);
	pop(b);
	push(a, x);
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	swap_a_b(t_stack **a, t_stack **b)
{
	swap(a, 's');
	swap(b, 's');
	write(1, "ss\n", 3);
}

void	rotate(t_stack	**a, char c)
{
	t_stack	*p;
	t_stack *head;
	t_stack *q;

	head = *a;
	*a = (*a)->next;
	p = *a;
	int val = pop(&head);
	while (p->next)
	{
		p = p ->next;
	}
	q = malloc(sizeof(t_stack));
	q ->val = val;
	p->next = q;
	(q) ->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);;
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rotate_a_b(t_stack **a, t_stack **b)
{
	rotate(a, 'r');
	rotate(b, 'r');
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack **a, char c)
{
	t_stack	*p;
	t_stack	*q;

	if (!*a)
		return ;
	p = *a;
	while (p->next)
	{
		q = p;
		p = p -> next;
	}
	q -> next = NULL;
	p -> next = *a;
	*a = p;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'r')
		return ;
	else
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 'r');
	reverse_rotate(b, 'r');
	write(1, "rrr\n", 4);
}
