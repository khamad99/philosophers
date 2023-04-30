/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:18:02 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/30 22:55:19 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_exit(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->num_philo)
		pthread_mutex_destroy(&philo->info->forks_m[i]);
	pthread_mutex_destroy(&philo->info->print_mutex);
	pthread_mutex_destroy(&philo->info->dead_m);
	pthread_mutex_destroy(&philo->info->meals_num_m);
	pthread_mutex_destroy(&philo->info->times_eaten_m);
	pthread_mutex_destroy(&philo->info->start_eating_m);
	pthread_mutex_destroy(&philo->info->last_meal_time_m);
}
