/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:40:59 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 23:31:31 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->status);
	printf("%lld %d %s", get_time() - philo->data->time_start, philo->id, str);
	pthread_mutex_unlock(&philo->data->status);
}
