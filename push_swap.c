/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:54:52 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/21 09:56:13 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int	len;

	if (!a)
		return (0);
	len = 0;
	while (a)
	{
		len ++;
		a = a -> next;
	}
	return (len);
}

void	check_cases(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 3)
			sort_three_ints(a, 'a');
		else if (stack_len(*a) == 5)
			sort_five(a, b);
		else if (stack_len(*a) < 250)
			sort(a, b, 'b');
		else
			sort(a, b, 'a');
	}
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	flag;

	flag = 1;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				change(&arr[j], &arr[j + 1]);
				flag = 0;
			}
			j++;
		}
		if (flag == 1)
			return ;
		i++;
	}
}

int	*insert_array(t_stack *a)
{
	int	*arr;
	int	i;
	int	len;

	i = 0;
	len = stack_len(a);
	arr = malloc(len * sizeof(int));
	if (!arr)
		return (0);
	while (i < len)
	{
		arr[i++] = a->val;
		a = a-> next;
	}
	bubble_sort(arr, len);
	return (arr);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	check_args(ac, av);
	fill_stack(ac, av, &a);
	check_cases(&a, &b);
}
