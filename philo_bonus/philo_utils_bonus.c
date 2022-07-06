/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:23:36 by lrieklin          #+#    #+#             */
/*   Updated: 2022/07/01 19:10:58 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all(pid_t *pid, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		kill(pid[i], SIGKILL);
		i++;
	}
}

void	philo_sleep(long long time)
{
	long long	start_time;

	start_time = get_time();
	usleep(time * 820);
	while (get_time() - start_time < time)
	{
		usleep(200);
	}
}
