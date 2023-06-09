/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:58:50 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/30 09:13:12 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
{
	long long	s;
	size_t		r;

	s = 1;
	r = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str
		== '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	if (s == -1 && r > 9223372036854775807)
		return (0);
	else if (s == 1 && r >= 9223372036854775807)
		return (-1);
	return (r * s);
}

void	print_timestamped_message(char *message, t_philo *philo, int id)
{
	unsigned long long	timestamp_ms;

	timestamp_ms = get_time_ms() - philo->info->start_time;
	pthread_mutex_lock(&philo->info->print_mutex);
	if (id == 0)
		printf("%llu %d %s\n", timestamp_ms, philo->id, message);
	else
		printf("%llu %d %s\n", timestamp_ms, id, message);
	pthread_mutex_unlock(&philo->info->print_mutex);
}
