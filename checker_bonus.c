/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:48:21 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/24 11:41:51 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_stack **a)
{
	t_stack	*b;
	char	*instra;
	int		len1;
	int		len2;

	len1 = stack_len(*a);
	b = NULL;
	instra = get_next_line(0);
	while (instra)
	{
		check_instraction(instra);
		check_swaps(a, &b, instra);
		check_rotates(a, &b, instra);
		check_rev_rotates(a, &b, instra);
		check_pushes(a, &b, instra);
		free(instra);
		instra = get_next_line(0);
	}
	len2 = stack_len(*a);
	if (is_sorted(*a) && len2 == len1)
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
	while (a)
		pop(&a);
}
