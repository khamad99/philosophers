/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:48:34 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/10 23:56:55 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_is_digit(char **argv)
{
	int	i;
	int	i2;

	i = 0;
	while(argv[i])
	{
		i2 = 0;
		while (argv[i][i2])
		{
			if (argv[i][i2] >= '0' && argv[i][i2] <= '9')
				i2++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
