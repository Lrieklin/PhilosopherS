/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:44:07 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 02:45:02 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	my_func(long res, int counter)
{
	if (counter > 10)
	{
		write(2, "Error check for int\n", 21);
		exit(1);
	}
	if (counter == 10 && res > 2147483647)
	{
		write(2, "Error check for int\n", 21);
		exit(1);
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
			exit(1);
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
