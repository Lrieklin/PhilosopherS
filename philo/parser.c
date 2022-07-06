/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:42:37 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/27 07:09:23 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
