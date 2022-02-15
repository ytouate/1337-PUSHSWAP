/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:47:39 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/15 20:44:24 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_descending(t_stack **a, t_stack **b)
{
	while (*a)
	{
		insert(b, a, 'b');
	}
	*a = *b;
}

void sort_three_ints(t_stack **a, char c)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->val;
	second = (*a)->next->val;
	third = (*a)->next->next->val;
	if (is_sorted(*a) == 1)
		return ;
	if (first > second && second < third)
	{
		rotate(a, c);
		if (!is_sorted(*a))
		{
			reverse_rotate(a, c);
			swap(a, c);
		}
	}
	else if (first < second && second > third)
	{
		reverse_rotate(a, c);
		if (!is_sorted(*a))
			swap(a, c);
	}
	else
	{
		swap(a, c);
		reverse_rotate(a, c);
	}
}

int ft_min(t_stack *a)
{
	int min;
	t_stack *p;

	p = a;
	min = a->val;
	while (a)
	{
		if (a->val < min)
			min = a->val;
		a = a->next;		
	}
	return get_index(p, min);
}

void sort_five(t_stack **a, t_stack **b)
{
	int min;
	int mid;
	int count;
	while (*a)
	{
		mid = stack_len(*a) / 2;
		min = get_index(*a, get_min(*a));
		if (min > mid + 1)
		{
			count = min - stack_len(*a) + 2;
			while (--count)
				reverse_rotate(a, 'a');
			insert(b, a, 'b');
		}
		else
		{
			while (--min)
				rotate(a, 'a');
			insert(b, a, 'b');
		}
	}
	while (*b)
		insert(a, b, 'b');
}

int get_index(t_stack *a, int val)
{
	int i;
	i = 1;
	while (a)
	{
		if (a->val == val)
			return i;
		i++;
		a = a->next; 
	}
	return i;
}

int get_min(t_stack *a)
{
	int min;
	t_stack *p;

	p = a;
	min = a->val;
	while (a)
	{
		if (a->val < min)
			min = a->val;
		a = a->next;		
	}
	return min;
}

int get_max(t_stack *a)
{
	int max;
	t_stack *p;

	p = a;
	max = a->val;
	while (a)
	{
		if (a->val > max)
			max = a->val;
		a = a->next;		
	}
	return get_index(p, max);
}
