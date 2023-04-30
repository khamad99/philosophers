/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:10:37 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/30 11:30:26 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->dead_m);
	if (philo->info->dead != 0)
	{
		print_timestamped_message("dead", philo, philo->info->dead);
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
		if (someone_dead(philo))
			return (2);
		usleep(20);
		if (all_done_eating(philo))
			return (1);
	}
	return (0);
}
