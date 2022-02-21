/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_instractions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:31:50 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/21 14:37:57 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_swaps(t_stack **a, t_stack **b, char *instra)
{
	if (ft_strcmp(instra, "sa\n"))
		swap2(a);
	else if (ft_strcmp(instra, "sb\n"))
		swap2(b);
	else if (ft_strcmp(instra, "ss\n"))
		combine(a, b, "ss\n");
	else
		return ;
}

void	check_rotates(t_stack **a, t_stack **b, char *instra)
{
	if (ft_strcmp(instra, "ra\n"))
		rotate2(a);
	else if (ft_strcmp(instra, "rb\n"))
		rotate2(b);
	else if (ft_strcmp(instra, "rr\n"))
		combine(a, b, "rr");
	else
		return ;
}

void	check_pushes(t_stack **a, t_stack **b, char *instra)
{
	if (ft_strcmp(instra, "pa\n"))
		insert2(a, b);
	else if (ft_strcmp(instra, "pb\n"))
		insert2(b, a);
	else
		return ;
}

void	check_rev_rotates(t_stack **a, t_stack **b, char *instra)
{
	if (ft_strcmp(instra, "rra\n"))
		reverse_rotate2(a);
	else if (ft_strcmp(instra, "rrb\n"))
		reverse_rotate2(b);
	else if (ft_strcmp(instra, "rrr\n"))
		combine(a, b, "rrr");
	else
		return ;
}

void	check_instraction(char *instra)
{
	if ((ft_strcmp(instra, "sa\n") == 1 || ft_strcmp(instra, "sb\n") == 1
			|| ft_strcmp(instra, "ss\n")) == 1)
	{
		return ;
	}
	else if ((ft_strcmp(instra, "ra\n") == 1 || ft_strcmp(instra, "rb\n") == 1
			|| ft_strcmp(instra, "rr\n")) == 1)
	{
		return ;
	}
	else if ((ft_strcmp(instra, "rra\n") == 1 || ft_strcmp(instra, "rrb\n") == 1
			|| ft_strcmp(instra, "rrr\n")) == 1)
	{
		return ;
	}
	else if ((ft_strcmp(instra, "pa\n") == 1 || ft_strcmp(instra, "pb\n") == 1))
	{
		return ;
	}
	else
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
