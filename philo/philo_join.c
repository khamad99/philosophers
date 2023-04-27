/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:14:12 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/20 18:38:23 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_join(t_philo *philo)
{
	int i;

	i = -1;
	while (++i < philo->info->num_philo)
		pthread_join(philo[i].thread, NULL);
}