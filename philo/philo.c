/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:02:32 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/26 14:30:43 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char** argv)
{
	t_info	info[1];
	t_philo	philo[MAX_PHILO];
	int flag;

	flag = 0;
	if (parceing_check(argc, argv))
		return (1);
	data_init(argc, argv, &flag, philo, info);
	if (flag)
	{
		printf("pthread creating faild\n");
		philo_exit(philo);
		return (1);
	}
	flag = monitoring(philo);
	if (flag == 2)
		return (1);
	else if (flag == 1)
		philo_join(philo);
	philo_exit(philo);
	return (0);
}
