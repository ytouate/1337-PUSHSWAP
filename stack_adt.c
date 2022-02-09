/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:49:40 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/08 13:53:54 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, int val)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	temp->next = NULL;
	temp -> val = val;
	if (!temp)
		return ;
	temp -> next = *a;
	*a = temp;
}

int	pop(t_stack **a)
{
	t_stack	*temp;
	int		x;

	if (!*a)
		return (-1);
	temp = *a;
	*a = (*a)-> next;
	x = temp->val;
	temp -> next = NULL;
	free(temp);
	return (x);
}

int	peek(t_stack *a, int pos)
{
	int	i;

	i = 0;
	while (i < pos - 1 && a)
	{
		a = a -> next;
		i++;
	}
	if (a)
		return (a->val);
	return (-1);
}

int	stack_top(t_stack *a)
{
	if (!a)
		return (-1);
	else
		return (a -> val);
}

int	stack_is_empty(t_stack *a)
{
	if (a)
		return (0);
	else
		return (1);
}