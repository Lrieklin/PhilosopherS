/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:49:48 by lrieklin          #+#    #+#             */
/*   Updated: 2022/07/01 19:24:44 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print(char *str, t_philo *philo)
{
	sem_wait(philo->print);
	printf("%lld %d %s", get_time() - philo->data->time_start, philo->id, str);
	sem_post(philo->print);
}
