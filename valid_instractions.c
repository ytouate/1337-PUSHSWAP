/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_instraction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:25 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/24 11:38:18 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks weather the instra is sa, sb or ss
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

// checks weather the instra is ra, rb or rr
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

// checks weather the instra is pa, pb
void	check_pushes(t_stack **a, t_stack **b, char *instra)
{
	if (ft_strcmp(instra, "pa\n"))
		insert2(a, b);
	else if (ft_strcmp(instra, "pb\n"))
		insert2(b, a);
	else
		return ;
}

// checks weather the instra is rra, rrb or rrr
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

/* combines all the functions above and 
checks if the instraction is valid or not*/
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
