/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:16:06 by lrieklin          #+#    #+#             */
/*   Updated: 2022/07/01 18:33:50 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_rules
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	count_of_eat;
}	t_rules;

typedef struct s_philo
{
	int				id;
	long			last_time_eat;
	int				count_eat;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_rules			*rules;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	status;
	long			time_start;
	t_philo			*philos;
	t_rules			*rules;
}	t_data;

int			ft_isdigit(const char *c);
int			ft_atoi(const char *str);
void		*ft_memset(void *b, int c, size_t len);

void		check_for_digit(int argc, char **argv);
void		check_for_int(int argc, char **argv);

int			create_rules(char **argv, t_rules *rules, int argc);
int			create_data(t_data *data);
void		give_forks_to_philo(t_data *data);
void		create_philo(t_data *data);
long long	get_time(void);
int			start_threads(t_data *data);
void		*philosopher(void *filos);
void		print(char *str, t_philo *philo);
void		get_forks(t_philo *philo);
void		philo_sleep(long long time);
int			factor(t_data *data, int argc);
int			eat_factor(t_data *data);
int			death_factor(t_data *data);
int			init_mutex(t_data *data);
void		free_thread(t_data *data);
void		free_struct(t_data *data);

#endif
