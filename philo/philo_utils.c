/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:12:28 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 23:32:00 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		ml_sec;

	gettimeofday(&time, NULL);
	ml_sec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ml_sec);
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

int	eat_factor(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		pthread_mutex_lock(&data->status);
		if (data->philos[i].count_eat >= data->rules->count_of_eat)
			j++;
		pthread_mutex_unlock(&data->status);
		i++;
	}
	if (j == data->rules->number_of_philosophers)
	{
		pthread_mutex_lock(&data->status);
		return (1);
	}
	return (0);
}

int	death_factor(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		pthread_mutex_lock(&data->status);
		if (get_time() - data->philos[i].last_time_eat
			>= data->rules->time_to_die)
		{
			pthread_mutex_unlock(&data->status);
			print("died\n", &data->philos[i]);
			pthread_mutex_lock(&data->status);
			return (1);
		}
		pthread_mutex_unlock(&data->status);
		i++;
	}
	return (0);
}

void	free_struct(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks != NULL)
	{
		while (i < data->rules->number_of_philosophers)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	pthread_mutex_destroy(&data->status);
}
