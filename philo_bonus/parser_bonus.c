/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:45:25 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 02:45:59 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_for_int(int argc, char **argv)
{
	int	i;
	int	res;

	i = 1;
	while (i < argc)
	{
		res = ft_atoi(argv[i]);
		i++;
	}
}
