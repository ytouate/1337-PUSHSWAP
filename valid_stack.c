/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:51:15 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/24 11:40:31 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks the int overflow
void	check_overflow(char **av, int i)
{
	if ((ft_atoi(av[i]) == -1 || ft_atoi(av[i]) == 0) && ft_strlen(av[i]) >= 10)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

// for the norm
static int	loop(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

// checks if the arguments are valid or not 
void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac <= 1)
		exit(EXIT_SUCCESS);
	while (av[++i])
	{
		if (ft_strcmp(av[i], ""))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		check_overflow(av, i);
		j = 0;
		if (av[i][0] == '-' && (av[i][1] >= '0' && av[i][1] <= '9'))
			j++;
		while (av[i][j])
		{
			if (loop(av[i][j]))
				j++;
		}
	}
}

// checks if there are any duplicates inside the stack
void	check_dup(int *arr, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
		{
			write(2, "Error\n", 6);
			free(arr);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

// fills the stack a using the 2D array av passed to it
void	fill_stack(int ac, char **av, t_stack **a)
{
	int		i;
	int		*save;
	int		j;

	save = malloc(sizeof(int) * ac);
	if (!save)
	{
		while (*a)
			pop(a);
		exit(EXIT_FAILURE);
	}
	i = 0;
	j = 0;
	while (ac-- > 1)
	{
		check_dup(save, j, ft_atoi(av[ac]));
		push(a, ft_atoi(av[ac]));
		save[i++] = ft_atoi(av[ac]);
		j++;
	}
	free(save);
}
