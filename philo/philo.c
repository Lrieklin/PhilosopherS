/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:16:23 by lrieklin          #+#    #+#             */
/*   Updated: 2022/07/01 18:45:50 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init(int argc, char **argv)
{
	t_data		*data;
	int			cr_rules;

	if (argc != 5 && argc != 6)
	{
		write(1, "Not enough input parametrs\n", 28);
		return (NULL);
	}
	data = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->rules = NULL;
	data->rules = (t_rules *)malloc(sizeof(t_rules));
	if (!data->rules)
		return (NULL);
	cr_rules = create_rules(argv, data->rules, argc);
	if (cr_rules == 1)
		return (NULL);
	create_data(data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	long long	time;
	int			st_thread;

	check_for_int(argc, argv);
	data = init(argc, argv);
	if (!data)
		return (1);
	create_philo(data);
	init_mutex(data);
	time = get_time();
	st_thread = start_threads(data);
	if (st_thread == 1)
		return (1);
	factor(data, argc);
	free_struct(data);
	free_thread(data);
	free(data);
	data = NULL;
}
