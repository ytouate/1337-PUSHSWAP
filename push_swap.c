/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:54:52 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/24 12:06:59 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*this function check the range (lenght) of the 
stack and call the approprita sorting function */
void	check_cases(t_stack **a, t_stack **b)
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

/*sort an array using bubble_sort*/
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

/* this function insert the element of stack a into an
 array and sorts them using the function "bubble sort"*/
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
	if (!is_sorted(a))
		check_cases(&a, &b);
	while (a)
		pop(&a);
}
