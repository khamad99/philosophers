/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:37:25 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/30 13:12:29 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX_PHILO 200

typedef struct s_info
{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_times_each_must_eat;
	int					meals_num;
	int					forks[MAX_PHILO];
	int					dead;
	unsigned long long	start_time;
	pthread_mutex_t		dead_m;
	pthread_mutex_t		start_eating_m;
	pthread_mutex_t		times_eaten_m;
	pthread_mutex_t		forks_m[MAX_PHILO];
	pthread_mutex_t		meals_num_m;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		last_meal_time_m;
	pthread_mutex_t		flag_m;
}	t_info;

typedef struct s_philo
{
	int					id;
	int					times_eaten;
	int					done_eating;
	int					lfork;
	int					rfork;
	int					flag;
	unsigned long long	last_meal_time;
	pthread_t			thread;
	pthread_t			dead_thread;
	t_info				*info;
}	t_philo;

int					parceing_check(int argc, char **argv);
int					ft_isdigit(int c);
long long			ft_atoi(const char *str);
int					data_init(int argc, char **argv,
						t_philo *philo, t_info *info);
void				*philo_thread(void *arg);
void				*dead_thread(void *arg);
void				philo_usleep(unsigned long long time);
unsigned long long	get_time_ms(void);
void				print_timestamped_message(char *message,
						t_philo *philosopher, int id);
void				philo_join(t_philo *philo);
void				philo_exit(t_philo *philo);
int					monitoring(t_philo *philo);
int					someone_dead(t_philo *philo);

#endif