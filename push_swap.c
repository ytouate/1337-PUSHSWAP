/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:54:52 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/09 10:32:34 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int	len;

	if (!a->val || !a)
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
	int i;
	int *save;
	int j;

	save = malloc(sizeof(int) * ac);
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

int is_descending(t_stack *a)
{
	t_stack	*p;
	while (a)
	{
		p = a;
		while (p->next)
		{
			if (p->val < p->next->val)
				return (0);
			p = p ->next;
		}
		a = a->next;
	}
	return (1);
}

int get_min(t_stack *a)
{
	int min;
	while (a)
	{
		if (stack_top(a) < min)
		{
			min = stack_top(a);
		}
		a = a->next;
	}
	return min;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac <= 1)
		return (0);
	a = NULL;
	b = NULL;
	check_args(av);
	fill_stack(ac, av, &a);
	if (is_sorted(a) == 1)
	{
		write(1, "Stack already sorted\n", 21);
		exit(EXIT_SUCCESS);
	}
	int i;
	i = 0;
	while (i < 2)
	{
		reverse_rotate(&a, 'a');
		i++;
	}
	sort_three_ints(&a, 'a');
	if (is_descending(a))
		sort_descending(&a, &b);
	display_stack(a);
}
