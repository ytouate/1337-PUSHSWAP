/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:53:56 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/24 11:44:09 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swaps the value of two ints */
void	change(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

// checks if the stack a is already sorted
int	is_sorted(t_stack *a)
{
	t_stack	*q;

	while (a)
	{
		q = a;
		while (q ->next)
		{
			if (q ->val > q->next->val)
				return (0);
			q = q->next;
		}
		a = a -> next;
	}
	return (1);
}

// gets the index of val inside a
int	get_index(t_stack *a, int val)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->val == val)
			return (i);
		i++;
		a = a-> next;
	}
	return (i);
}

// returns the min value of a
int	get_min(t_stack *a)
{
	int		min;
	t_stack	*p;

	p = a;
	min = a->val;
	while (a)
	{
		if (a->val < min)
			min = a->val;
		a = a-> next;
	}
	return (min);
}

// returns the max value of a
int	get_max(t_stack *a)
{
	int		max;
	t_stack	*p;

	p = a;
	max = a->val;
	while (a)
	{
		if (a->val > max)
			max = a->val;
		a = a->next;
	}
	return (max);
}
