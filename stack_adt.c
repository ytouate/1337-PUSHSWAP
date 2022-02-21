/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:49:40 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/21 12:10:32 by ytouate          ###   ########.fr       */
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
