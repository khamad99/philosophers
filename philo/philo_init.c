/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:01:06 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/27 14:10:48 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_philo *philo)
{
	int i;

	i = -1;
	while (++i < philo->info->num_philo)
		pthread_mutex_init(&philo->info->forks_m[i], NULL);
	pthread_mutex_init(&philo->info->print_mutex, NULL);
	pthread_mutex_init(&philo->info->dead_m, NULL);
	pthread_mutex_init(&philo->info->meals_num_m, NULL);

}

void	info_init(t_info *info, char **argv, int argc)
{
	int i;

	i = -1;
	info->num_philo = ft_atoi(argv[1]);
	info->start_time = get_time_ms();
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->meals_num = 0;
	info->dead = 0;
	if (argc == 6)
		info->num_times_each_must_eat = ft_atoi(argv[5]);
	else
		info->num_times_each_must_eat = -1;
	while (++i < info->num_philo)
		info->forks[i] = 0;
	
}


void	philo_init(int *flag, t_info *info, t_philo	*philo)
{
	int		i;

	i = -1;
	while (++i < info->num_philo) 
	{
		philo[i].id = i + 1;
		philo[i].times_eaten = 0;
		philo[i].last_meal_time = 0;
		philo[i].lfork = i;
		if (i - 1 < 0)
			philo[i].rfork = info->num_philo - 1;
		else
			philo[i].rfork = i - 1;
		philo[i].info = info;
		if (pthread_create(&philo[i].thread, NULL, philo_thread, &philo[i]) != 0 )
			*flag = 1;
	}
}

void	data_init(int argc, char **argv, int *flag, t_philo *philo, t_info *info)
{	
	info_init(info, argv, argc);
	philo_init(flag, info, philo);
	mutex_init(philo);
}
