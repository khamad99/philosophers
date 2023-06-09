/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_usleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:00:24 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/29 13:20:41 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	philo_usleep(unsigned long long time)
{
	unsigned long long	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < time)
		usleep(time / 10);
}
