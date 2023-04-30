/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:27:58 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/30 13:18:01 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_flag(t_philo	*philo)
{
	pthread_mutex_lock(&philo->info->flag_m);
	if (philo->flag)
	{
		pthread_mutex_unlock(&philo->info->flag_m);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->flag_m);
	return (0);
}

void	*dead_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		if (check_flag(philo))
			break ;
		pthread_mutex_lock(&philo->info->last_meal_time_m);
		if (get_time_ms() - philo->info->start_time - philo
			->last_meal_time >= (unsigned long long)philo->info->time_to_die)
		{
			pthread_mutex_unlock(&philo->info->last_meal_time_m);
			pthread_mutex_lock(&philo->info->dead_m);
			philo->info->dead = philo->id;
			pthread_mutex_unlock(&philo->info->dead_m);
			return (0);
		}
		else
			pthread_mutex_unlock(&philo->info->last_meal_time_m);
		usleep(50);
	}
	return (0);
}
