/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:10:37 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/27 21:44:28 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_dead(t_philo *philo)
{
	if (get_time_ms() - philo->info->start_time - philo
		->last_meal_time >= (unsigned long long)philo->info->time_to_die)
	{
		pthread_mutex_lock(&philo->info->dead_m);
		philo->info->dead = 1;
		pthread_mutex_unlock(&philo->info->dead_m);
		print_timestamped_message("died", philo);
		return (1);
	}
	pthread_mutex_lock(&philo->info->dead_m);
	if (philo->info->dead)
	{
		pthread_mutex_unlock(&philo->info->dead_m);
		return (1);
	}
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
		pthread_mutex_unlock(&philo->info->meals_num_m);
	}
	return (0);
}

int	monitoring(t_philo *philo)
{
	while (1)
	{
		usleep(10);
		if (all_done_eating(philo))
			return (1);
		else if (someone_dead(philo))
			return (2);
	}
	return (0);
}
