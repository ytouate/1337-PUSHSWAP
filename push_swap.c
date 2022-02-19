/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:54:52 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/19 20:37:12 by ytouate          ###   ########.fr       */
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

void	display_stack(t_stack *a)
{
	if (!a)
		return ;
	while (a)
	{
		printf("%d\n", a->val);
		a = a->next;
	}
}

void	fill_stack(int ac, char **av, t_stack **a)
{
	int		i;
	int		*save;
	int		j;

	save = malloc(sizeof(int) * ac);
	if (!save)
		return ;
	i = 0;
	j = 0;
	while (ac-- > 1)
	{
		check_dup(save, j, ft_atoi(av[ac]));
		push(a, ft_atoi(av[ac]));
		save[i++] = ft_atoi(av[ac]);
		j++;
	}
	free(save);
}

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

void	check_cases(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 3)
			sort_three_ints(a, 'a');
		if (stack_len(*a) == 5)
			sort_five(a, b);
		if (stack_len(*a) < 250)
			sort(a, b, 'b');
		else
			sort(a, b, 'a');
	}
}

void	change(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
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

int*	insert_array(t_stack *a)
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

int	search(int *arr, int val, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		if (val == arr[i])
			return (i - 1);
		i++;
	}
	return (INT_MIN);
}

void	index_element(t_stack *a)
{
	int	i;
	int	len;
	int	*arr;

	arr = insert_array(a);
	i = 0;
	len = stack_len(a);
	while (a)
	{
		(a)-> index = search(arr, (a)->val, len);
		a = (a)-> next;
	}
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
