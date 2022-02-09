/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:46:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/09 10:33:07 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int     ft_atoi(const char *str)
{
        int                             i;
        int                             sign;
        unsigned long   result;

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
        {

                result = (10 * result) + str[i++] - '0';
        }
		if ((result > 2147483648 && sign == -1) || (result > 2147483647 && sign == 1))
			return(-1);
        return ((((int)result) * sign));
}

static char	*temp_strcpy(char *dst, const char *src)
{
	char	*ptr;

	ptr = dst;
	if (dst == NULL)
	{
		return (NULL);
	}
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*duplicated_str;

	s1_len = ft_strlen(s1);
	duplicated_str = malloc(s1_len * sizeof(char) + 1);
	if (!duplicated_str)
		return (NULL);
	temp_strcpy (duplicated_str, s1);
	return (duplicated_str);
}

static int	get_parts(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if ((s[0] != c && i == 0) || (s[i] != c && s[i - 1] == c && s[i]))
			n++;
		i++;
	}
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	size_t			sub_index;
	unsigned int	i;

	if (!s)
		return (NULL);
	sub_index = 0;
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	while (s[i])
	{
		if (i >= start && sub_index < len)
		{
			sub_s[sub_index++] = s[i];
		}
		i++;
	}
	sub_s[sub_index] = '\0';
	return (sub_s);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**result;
	int		i;
	int		o;

	i = 0;
	if (!s)
		return (NULL);
	result = malloc((get_parts (s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	while (index < get_parts (s, c))
	{
		while (s[i] == c && s[i])
			i++;
		o = i;
		while (s[i] != c && s[i])
			i++;
		result[index] = ft_substr(s, o, i - o);
		index++;
	}
	result[index] = NULL;
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t i;
	
	i = -1;
	while (s[++i]);
	return i;
}