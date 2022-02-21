/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:48:17 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/21 10:49:57 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap2(t_stack **a)
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
}

void	insert2(t_stack **a, t_stack **b)
{
	int	x;

	if (!*b)
		return ;
	x = stack_top(*b);
	pop(b);
	push(a, x);
}

void	rotate2(t_stack	**a)
{
	t_stack	*p;
	t_stack	*head;
	t_stack	*q;
	int		val;

	head = *a;
	*a = (*a)->next;
	p = *a;
	val = pop(&head);
	while (p->next)
	{
		p = p ->next;
	}
	q = malloc(sizeof(t_stack));
	q ->val = val;
	p->next = q;
	(q)-> next = NULL;
}

void	reverse_rotate2(t_stack **a)
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
}

void	combine(t_stack **a, t_stack **b, char *arg)
{
	if (ft_strcmp(arg, "rrr"))
	{
		reverse_rotate2(a);
		reverse_rotate2(b);
	}
	else if (ft_strcmp(arg, "ss"))
	{
		swap2(a);
		swap2(b);
	}
	else if (ft_strcmp(arg, "rr"))
	{
		rotate2(a);
		rotate2(b);
	}
	else
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
}