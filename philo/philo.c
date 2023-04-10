/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:02:32 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/11 00:26:18 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int thread_num;
	int i;

	if (argc < 5 || argc > 6)
		return (0);
	if (check_is_digit(argv))
		return (0);
	thread_num = ft_atoi(argv[1]);
	i = 0;
	pthread_t philo[thread_num];
	
	while (i++ <= thread_num)
	{
		if (pthread_create(&philo[i], NULL, &eating, NULL) != 0)
			return (0);
	}
	


	
}