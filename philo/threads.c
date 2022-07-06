/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:49:29 by lrieklin          #+#    #+#             */
/*   Updated: 2022/07/01 18:34:01 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *filos)
{
	t_philo	*philo;

	philo = (t_philo *)filos;
	usleep((philo->id + 1) % 2 * 500);
	while (1)
	{
		get_forks(philo);
		print("is eating\n", philo);
		pthread_mutex_lock(&philo->data->status);
		philo->last_time_eat = get_time();
		pthread_mutex_unlock(&philo->data->status);
		philo_sleep(philo->rules->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(&philo->data->status);
		philo->count_eat += 1;
		pthread_mutex_unlock(&philo->data->status);
		print("is sleeping\n", philo);
		philo_sleep(philo->rules->time_to_sleep);
		print("is thinking\n", philo);
	}
	return (0);
}

int	factor(t_data *data, int argc)
{
	while (1)
	{
		if (death_factor(data) == 1)
			return (1);
		if (argc == 6 && eat_factor(data) == 1)
			return (1);
		usleep(300);
	}
	return (0);
}

void	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print("has taken a fork\n", philo);
	pthread_mutex_lock(philo->right_fork);
	print("has taken a fork\n", philo);
}

int	start_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		if (pthread_create(&data->thread[i], NULL,
				philosopher, &data->philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		if (pthread_detach(data->thread[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
