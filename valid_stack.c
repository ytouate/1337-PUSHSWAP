/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:51:15 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/08 13:52:05 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_overflow(char **av, int i)
{
	if ((ft_atoi(av[i]) == -1 || ft_atoi(av[i]) == 0) && ft_strlen(av[i]) >= 10)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
}

void	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[++i])
	{
		check_overflow(av, i);
		j = 0;
		if (av[i][0] == '-' && (av[i][1] >= '0' && av[i][1] <= '9'))
			j++;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
			{
				write(2, "Error\n", 7);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void check_dup(int *arr, int size, int val)
{
	int i;
	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
		{

			write(1, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
