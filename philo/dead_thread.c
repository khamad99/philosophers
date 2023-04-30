/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:27:58 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/30 09:31:07 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		pthread_mutex_lock(&philo->info->last_meal_time_m);
		if (get_time_ms() - philo->info->start_time - philo
			->last_meal_time >= (unsigned long long)philo->info->time_to_die)
		{
			pthread_mutex_unlock(&philo->info->last_meal_time_m);
			pthread_mutex_lock(&philo->info->dead_m);
			philo->info->dead = 1;
			philo->info->dead_id = philo->id;
			pthread_mutex_unlock(&philo->info->dead_m);
		}
		else
			pthread_mutex_unlock(&philo->info->last_meal_time_m);
		usleep(50);
	}
	return (0);
}