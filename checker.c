/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:48:21 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/22 13:52:45 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_stack **a)
{
	t_stack	*b;
	char	*instra;

	b = NULL;
	instra = get_next_line(1);
	while (instra)
	{
		check_instraction(instra);
		check_swaps(a, &b, instra);
		check_rotates(a, &b, instra);
		check_rev_rotates(a, &b, instra);
		check_pushes(a, &b, instra);
		instra = get_next_line(1);
	}
	while (*a)
		*a = (*a)->next;
	if (is_sorted(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	a = NULL;
	check_args(ac, av);
	fill_stack(ac, av, &a);
	checker(&a);
}
