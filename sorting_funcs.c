/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:47:39 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/09 10:25:26 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_descending(t_stack **a, t_stack **b)
{
	while (*a)
	{
		insert(b, a, 'b');
	}
	*a = *b;
}
void sort_three_ints(t_stack **a, char c)
{
	t_stack	*p;

	p = *a;
	if ((*a)->val > (*a)->next->val)
		swap(a, c);
	if ((*a)->val < (*a)->next->val && (*a)->next->next->val < (*a)->val)
		reverse_rotate(a, c);
}