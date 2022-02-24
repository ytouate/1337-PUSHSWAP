/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:49:40 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/24 11:45:42 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// add val at the top of a
void	push(t_stack **a, int val)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return ;
	temp->next = NULL;
	temp -> val = val;
	if (!temp)
		return ;
	temp -> next = *a;
	*a = temp;
}

// pops out the first element at the top of a
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

// returns the value stored at the top of a
int	stack_top(t_stack *a)
{
	if (!a)
		return (-1);
	else
		return (a -> val);
}

// checks if stack a is empty
int	stack_is_empty(t_stack *a)
{
	if (a)
		return (0);
	else
		return (1);
}

// returns the lenght of the stack
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
