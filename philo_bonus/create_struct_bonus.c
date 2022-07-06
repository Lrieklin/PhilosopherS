/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:47:01 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 10:30:13 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_rules(char **argv, t_rules *rules, int argc)
{
	rules->number_of_philosophers = atoi(argv[1]);
	rules->time_to_die = atoi(argv[2]);
	rules->time_to_eat = atoi(argv[3]);
	rules->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		rules->count_of_eat = atoi(argv[5]);
}

int	create_data(t_data *data)
{
	data->time_start = get_time();
	data->pid = (pid_t *)
		malloc((data->rules->number_of_philosophers) * sizeof(pid_t));
	if (!data->pid)
		return (1);
	data->philos = (t_philo *)
		malloc((data->rules->number_of_philosophers) * sizeof(t_philo));
	if (!data->philos)
		return (1);
	return (0);
}

int	init_sem(t_data *data)
{
	sem_unlink("philo_forks");
	sem_unlink("philo_print");
	sem_unlink("philo_status8");
	sem_unlink("philo_eat");
	data->forks = sem_open("philo_forks", O_CREAT, 777,
			data->rules->number_of_philosophers);
	if (!data->forks)
		return (1);
	data->print = sem_open("philo_print", O_CREAT, 777, 1);
	if (!data->print)
		return (1);
	data->status = sem_open("philo_status8", O_CREAT, 777, 1);
	if (!data->status)
		return (1);
	data->eat = sem_open("philo_eat", O_CREAT, 777, 0);
	if (!data->eat)
		return (1);
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rules->number_of_philosophers)
	{
		data->philos[i].id = i + 1;
		data->philos[i].count_eat = 0;
		data->philos[i].rules = data->rules;
		data->philos[i].data = data;
		data->philos[i].last_time_eat = get_time();
		data->philos[i].print = data->print;
		data->philos[i].status = data->status;
		data->philos[i].eat = data->eat;
		data->philos[i].forks = data->forks;
		i++;
	}
}
