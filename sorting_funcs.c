/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:47:39 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/19 20:57:08 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_ints(t_stack **a, char c)
{
	if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->next->next->val)
	{
		rotate(a, c);
		if (!is_sorted(*a))
		{
			reverse_rotate(a, c);
			swap(a, c);
		}
	}
	else if ((*a)->val < (*a)->next->val
		&& (*a)->next->val > (*a)->next->next->val)
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

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	mid;
	int	count;

	while (stack_len(*a) > 3)
	{
		mid = stack_len(*a) / 2;
		min = get_index(*a, get_min(*a));
		if (min <= mid)
		{
			while (min--)
				rotate(a, 'a');
			insert(b, a, 'b');
		}
		else
		{
			count = stack_len(*a) - min;
			while (count--)
				reverse_rotate(a, 'a');
			insert(b, a, 'b');
		}
	}
	sort_three_ints(a, 'a');
	while (*b)
		insert(a, b, 'a');
}

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
	return max;
}

int	n_exist(int *arr, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}

void	sort(t_stack **a, t_stack **b, const char c)
{
	int		*sorted_array;
	int		p;
	int		end;
	int		j;
	int		len;

	len	= stack_len(*a);
	end	= 0;
	j	= 0;
	sorted_array = insert_array(*a);
	while (*a && len > 0)
	{
		if (c == 'a')
			p = stack_len(*a) / 10 + 1;
		else
			p = stack_len(*a) / 3 + 1;
		end += p;
		j = p;
		while (*a != NULL && j)
		{
			if (n_exist(sorted_array, end, (*a)->val))
			{
				insert(b, a, 'b');
				j--;
				len--;
			}
			else
				rotate(a, 'a');
		}
	}
	p = 0;
	j = 0;
	while (*b)
	{
		p = get_index(*b, get_max(*b));
		if (p <= stack_len(*b) / 2)
		{
			j = p;
			while (j > 0)
			{
				rotate(b, 'b');
				j--;
			}
			insert(a, b, 'a');
		}
		else
		{
			j = stack_len(*b) - p + 1;
			while (--j > 0)
				reverse_rotate(b, 'b');
			insert(a, b, 'a');
		}
	}
}
