/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:10:37 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/30 22:08:19 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_dead(t_philo *philo)
{
	int	i;
	int	num;

	i = -1;
	num = philo->info->num_philo;
	while (++i < num)
	{
		pthread_mutex_lock(&philo->info->last_meal_time_m);
		if (get_time_ms() - philo->info->start_time - philo
			->last_meal_time >= (unsigned long long)philo->info->time_to_die)
		{
			pthread_mutex_unlock(&philo->info->last_meal_time_m);
			pthread_mutex_lock(&philo->info->dead_m);
			philo->info->dead = philo->id;
			pthread_mutex_unlock(&philo->info->dead_m);
			return (1);
		}
		else
			pthread_mutex_unlock(&philo->info->last_meal_time_m);
		philo++;
	}
	return (0);
}

int	someone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->dead_m);
	if (philo->info->dead != 0)
	{
		pthread_mutex_unlock(&philo->info->dead_m);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->info->dead_m);
	return (0);
}

int	all_done_eating(t_philo *philo)
{
	if (philo->info->num_times_each_must_eat != -1)
	{
		pthread_mutex_lock(&philo->info->meals_num_m);
		if (philo->info->meals_num == philo->info->num_philo)
		{
			pthread_mutex_unlock(&philo->info->meals_num_m);
			return (1);
		}
		else
			pthread_mutex_unlock(&philo->info->meals_num_m);
	}
	return (0);
}

int	monitoring(t_philo *philo)
{
	while (1)
	{
		usleep(20);
		if (philo_dead(philo))
			return (2);
		if (all_done_eating(philo))
			return (1);
	}
	return (0);
}
