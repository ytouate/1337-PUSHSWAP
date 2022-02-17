/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:47:39 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/17 14:12:27 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int len;
	int count;
	len = stack_len(*a);
	while (len > 3)
	{
		mid = stack_len(*a) / 2;
		min = get_index(*a, get_min(*a));
		if (min <= mid)
		{
			count = min;
			while (count--)
				rotate(a, 'a');
			insert(b, a, 'b');
			len--;
		}
		else
		{
			count = stack_len(*a) - min;
			while (count--)
				reverse_rotate(a, 'a');
			insert(b, a, 'b');
			len--;
		}
	}
	sort_three_ints(a, 'a');
	while (*b)
		insert(a, b, 'a');
}

int get_index(t_stack *a, int val)
{

	
	int i;
	i = 0;
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

int n_exist(int *arr, int start, int end, int val)
{
	int i;
	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}
int search_en
// void sort(t_stack **a, t_stack **b)
// {
// 	//int min;
// 	int to_push;
// 	int *arr;
// 	int i;
// 	if (!b)
// 		printf("b is empty\n");
// 	i = 0;
// 	arr = inesrt_array(*a);
// 	while (*a)
// 	{
// 		to_push = stack_len(*a) / 5 + 1;
		
// 	}
// }