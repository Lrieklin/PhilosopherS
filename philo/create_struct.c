/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 04:34:57 by lrieklin          #+#    #+#             */
/*   Updated: 2022/07/01 18:46:43 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_rules(char **argv, t_rules *rules, int argc)
{
	rules->number_of_philosophers = 0;
	rules->time_to_die = 0;
	rules->time_to_eat = 0;
	rules->time_to_sleep = 0;
	rules->count_of_eat = 0;
	if (atoi(argv[1]) == 0)
	{
		write(2, "Uncorrect count of philosophers\n", 33);
		return (1);
	}
	else
		rules->number_of_philosophers = atoi(argv[1]);
	rules->time_to_die = atoi(argv[2]);
	rules->time_to_eat = atoi(argv[3]);
	rules->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		rules->count_of_eat = atoi(argv[5]);
	return (0);
}

int	create_data(t_data *data)
{
	data->time_start = get_time();
	data->philos = NULL;
	data->thread = NULL;
	data->forks = NULL;
	data->philos = (t_philo *)
		malloc((data->rules->number_of_philosophers) * sizeof(t_philo));
	if (!data->philos)
		return (1);
	data->thread = (pthread_t *)malloc((data->rules->number_of_philosophers)
			* sizeof(pthread_t));
	if (!data->thread)
		return (1);
	data->forks = (pthread_mutex_t *)
		malloc((data->rules->number_of_philosophers)
			* sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	return (0);
}

void	check(t_philo *philo, t_data *data, int i, int count)
{
	if (count == 1)
	{
		philo[0].left_fork = &(data->forks[0]);
		philo[0].right_fork = &(data->forks[0]);
	}
	else if (data->rules->number_of_philosophers != 1)
	{
		philo[i].left_fork = &(data->forks[i]);
		philo[i].right_fork = &(data->forks[count - 1]);
	}	
}

void	give_forks_to_philo(t_data *data)
{
	t_philo		*philo;
	static int	i;
	int			count;

	count = data->rules->number_of_philosophers;
	philo = data->philos;
	if (philo[i].id == 1)
	{
		check(philo, data, i, count);
	}
	else if (philo[i].id == count)
	{
		philo[i].left_fork = &(data->forks[count - 1]);
		philo[i].right_fork = &(data->forks[count - 2]);
	}
	else
	{
		philo[i].left_fork = &(data->forks[i]);
		philo[i].right_fork = &(data->forks[i - 1]);
	}
	i++;
}

void	create_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		data->philos[i].data = data;
		data->philos[i].rules = data->rules;
		data->philos[i].id = i + 1;
		data->philos[i].count_eat = 0;
		data->philos[i].last_time_eat = get_time();
		give_forks_to_philo(data);
		i++;
	}
}
