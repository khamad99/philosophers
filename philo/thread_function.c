/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:09:06 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/27 15:01:53 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	done_eating(t_philo *philo)
{
	if (philo->times_eaten == philo->info->num_times_each_must_eat)
	{
		pthread_mutex_lock(&philo->info->meals_num_m);
		philo->info->meals_num++;
		pthread_mutex_unlock(&philo->info->meals_num_m);
		return (1);
	}
	return (0);
}

void	release_forks(t_philo *philo)
{
		philo->info->forks[philo->lfork] = 0;
		philo->info->forks[philo->rfork] = 0;
		philo->times_eaten++;
		philo->last_meal_time = get_time_ms() - philo->info->start_time;
		pthread_mutex_unlock(&philo->info->forks_m[philo->lfork]);
		pthread_mutex_unlock(&philo->info->forks_m[philo->rfork]);
		if (philo->times_eaten < philo->info->num_times_each_must_eat || philo->info->num_times_each_must_eat == -1)
		{
			print_timestamped_message("is sleeping", philo);
			philo_usleep(philo->info->time_to_sleep);
		}
}

void	get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks_m[philo->lfork]);
	pthread_mutex_lock(&philo->info->forks_m[philo->rfork]);
	philo->info->forks[philo->lfork] = 1;
	philo->info->forks[philo->rfork] = 1;
	print_timestamped_message("has taken a fork", philo);
	print_timestamped_message("has taken a fork", philo);
	print_timestamped_message("is eating", philo);
	philo_usleep(philo->info->time_to_eat);
	release_forks(philo);
}

int	check_forks(t_philo *philo)
{
	int lfork;
	int rfork;
	int is_dead;

	pthread_mutex_lock(&philo->info->forks_m[philo->lfork]);
	lfork = philo->info->forks[philo->lfork];
	pthread_mutex_unlock(&philo->info->forks_m[philo->lfork]);
	pthread_mutex_lock(&philo->info->forks_m[philo->rfork]);
	rfork = philo->info->forks[philo->rfork];
	pthread_mutex_unlock(&philo->info->forks_m[philo->rfork]);
	pthread_mutex_lock(&philo->info->dead_m);
	is_dead = philo->info->dead;
	pthread_mutex_unlock(&philo->info->dead_m);
	if (!lfork && !rfork && !is_dead)
		get_forks(philo);
	else
		return (0);
	return (1);
}

void* philo_thread(void* arg)
{
	t_philo	*philo = (t_philo *) arg;

	if (philo->id % 2 == 1)
		philo_usleep(3);
	while (done_eating(philo) == 0 && someone_dead(philo) == 0)
	{
		print_timestamped_message("is thinking", philo);
		while (1)
		{
			if (check_forks(philo))
				break;
			philo_usleep(5);
		}
	}
	return (0);
}
