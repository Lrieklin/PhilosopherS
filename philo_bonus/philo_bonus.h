/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:07:37 by lrieklin          #+#    #+#             */
/*   Updated: 2022/07/01 19:01:40 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data	t_data;

typedef struct s_rules
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		count_of_eat;
}	t_rules;

typedef struct s_philo
{
	int				id;
	long			last_time_eat;
	int				count_eat;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*status;
	sem_t			*all_eat;
	t_rules			*rules;
	t_data			*data;
	sem_t			*eat;
}	t_philo;

typedef struct s_data
{
	pid_t			*pid;
	long			time_start;
	pthread_t		thread;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*status;
	sem_t			*eat;
	t_philo			*philos;
	t_rules			*rules;
}	t_data;

void		check_for_int(int argc, char **argv);
void		create_rules(char **argv, t_rules *rules, int argc);
int			create_data(t_data *data);
int			init_sem(t_data *data);
void		init_philo(t_data *data);
int			launch(t_data *data);
void		*philo_launch(void	*data);
long long	get_time(void);
void		philo_sleep(long long time);
void		kill_all(pid_t *pid, int count);
void		print(char *str, t_philo *philo);
int			ft_atoi(const char *str);
int			ft_isdigit(const char *str);
void		forks_sem(t_philo *philo);

#endif