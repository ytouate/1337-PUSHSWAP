/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:54:52 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/15 20:34:51 by ytouate          ###   ########.fr       */
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

void	fill_stack(int ac, char **av, t_stack **a, char c)
{
	int i;
	int *save;
	int j;
	if (c == 'a')
		c = 0;
	else
		c = 1;
	save = malloc(sizeof(int) * ac);
	i = 0;
	j = 0;
	while (ac-- > 1)
	{
		check_dup(save, j, ft_atoi(av[ac - c]));
		push(a, ft_atoi(av[ac - c]));
		save[i++] = ft_atoi(av[ac - c]);
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

int count(char **av)
{
	int i;
	int j;
	int len;
	i = -1;
	len = 0;

	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if ((av[i][j] >= '0' && av[i][j] <= '9') && (av[i][j + 1] < '0' || av[i][j + 1] > '9'))
				len++;
	}
	return len;
}

void check_cases(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 3)
			sort_three_ints(a, 'a');
		if (stack_len(*a) == 5)	
			sort_five(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char **argv;

	a = NULL;
	b = NULL;
	if (ac == 2)
	{
		argv = ft_split(av[1], ' ');
		check_args(count(argv) + 1, argv, 'b');
		fill_stack(count(argv) + 1, argv, &a, 'b');
	}
	else
	{
		check_args(ac, av, 'a');
		fill_stack(ac, av, &a, 'a');
	}
	check_cases(&a, &b);
	display_stack(a);
}