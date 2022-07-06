/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:28:19 by lrieklin          #+#    #+#             */
/*   Updated: 2022/07/01 18:37:59 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	my_func(long res, int counter)
{
	if (counter > 10)
	{
		write(2, "Error check for int\n", 21);
		return (1);
	}
	if (counter == 10 && res > 2147483647)
	{
		write(2, "Error check for int\n", 21);
		return (1);
	}
	return ((int)res);
}

static const char	*ft_plus_minus(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			write(2, "Error a negative number\n", 25);
			return (NULL);
		}
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int				i;
	long			res;
	int				counter;

	i = 0;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	str = ft_plus_minus(str);
	if (!ft_isdigit(str))
		return (0);
	counter = 0;
	while (str[i + counter] >= '0' && str[i + counter] <= '9' )
	{
		res = res * 10 + str[i + counter] - '0';
		counter++;
	}
	return (my_func(res, counter));
}

int	ft_isdigit(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (j < i)
	{
		if (str[j] >= 48 && str[j] <= 57)
			j++;
		else
		{
			write(1, "Error, uncorrect characters\n", 29);
			return (0);
		}
	}
	return (1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*new_b;

	new_b = (char *)b;
	i = 0;
	while (i < len)
	{
		new_b[i] = (unsigned char)c;
		i++;
	}
	return ((void *)new_b);
}
