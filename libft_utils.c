/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:46:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/21 09:50:02 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\r')
		|| (str[i] == '\n') || (str[i] == '\v') || (str[i] == '\f'))
			i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
				sign = -1;
	while (str[i] <= '9' && str[i] >= '0')
			result = (10 * result) + str[i++] - '0';
	if ((result > 2147483648 && sign == -1)
		|| (result > 2147483647 && sign == 1))
		return (-1);
	return ((((int)result) * sign));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str, char *s)
{
	int	i;

	i = 0;
	while (str[i] || s[i])
	{
		if (str[i] != s[i])
			return (0);
		i++;
	}
	return (1);
}
