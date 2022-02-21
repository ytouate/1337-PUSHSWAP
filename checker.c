/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:48:21 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/21 09:52:45 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void checker(t_stack **a)
{
	t_stack	*b;
	char	*intra;

	instra = get_next_line(1);
	while (instra)
	{
		if (ft_strcmp(instra, "sa\n"))
			swap2(a);
		else if ft_strcmp(instra, "sb\n")
			swap2(&b);
		else if ft_strcmp(instra, "ss\n")
			combine(a, &b, "ss");
		else if ft_strcmp(instra, "pa\n")
			insert2(a, b);
		else if ft_strcmp(instra, "pb\n")
			insert2(b, a);
		else if ft_strcmp(instra, "ra\n")
			rotate2(a);
		else if ft_strcmp(instra, "rb\n")
			rotate2(&b);
		else if ft_strcmp(instra, "rr\n")
			combine(a, &b, "rr");
		else if ft_strcmp(instra, "rra\n")
			reverse_rotate2(a);
		else if ft_strcmp(instra, "rrb\n")
			reverse_rotat2(&b);
		else if ft_strcmp(instra, "rrr\n")
			combine(a, &b, "rrr");
		else
		{
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		instra = get_next_line(1);
	}
}

int main(int ac, char **av)
{
	t_stack *a;
	check_args(ac, av);
	fill_stack(ac, av, a);
	checker(&a);
	
}