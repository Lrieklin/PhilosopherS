/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lounch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:04:18 by lrieklin          #+#    #+#             */
/*   Updated: 2022/07/01 19:36:45 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	factor_smetri(t_philo *philo)
{
	while (1)
	{
		sem_wait(philo->status);
		if (get_time() - philo->last_time_eat
			>= philo->rules->time_to_die)
		{
			print("died\n", philo);
			exit(1);
		}
		sem_post(philo->status);
		usleep(300);
	}
	return (0);
}

int	launch(t_data *data)
{
	pthread_t		thr;
	int				i;

	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
		{
			printf("ERROR");
			kill_all(data->pid, i);
			exit(1);
		}
		if (data->pid[i] == 0)
		{
			pthread_create(&thr, NULL, philo_launch,
				(void *)&(data->philos[i]));
			pthread_detach(thr);
			factor_smetri(&(data->philos[i]));
		}
		else
			i++;
	}
	return (0);
}

void	*philo_launch(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id > philo->rules->number_of_philosophers / 2)
	{
		philo_sleep(philo->rules->time_to_sleep);
	}
	while (1)
	{
		forks_sem(philo);
		philo_sleep(philo->rules->time_to_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		sem_wait(philo->status);
		philo->count_eat += 1;
		if (philo->count_eat == philo->rules->count_of_eat)
			sem_post(philo->eat);
		sem_post(philo->status);
		print("is sleeping\n", philo);
		philo_sleep(philo->rules->time_to_eat);
		print("is thinking\n", philo);
	}
	return (0);
}

void	forks_sem(t_philo *philo)
{
	sem_wait(philo->forks);
	print("has taken a fork\n", philo);
	sem_wait(philo->forks);
	print("has taken a fork\n", philo);
	print("is eating\n", philo);
	sem_wait(philo->status);
	philo->last_time_eat = get_time();
	sem_post(philo->status);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		ml_sec;

	gettimeofday(&time, NULL);
	ml_sec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ml_sec);
}
