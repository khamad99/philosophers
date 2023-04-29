/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:48:34 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/29 22:46:41 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_is_digit(char **argv)
{
	int	i;
	int	i2;

	i = 0;
	while (argv[++i])
	{
		i2 = 0;
		while (argv[i][i2])
		{
			if (ft_isdigit(argv[i][i2]))
				i2++;
			else
				return (1);
		}
	}
	return (0);
}

int	parceing_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	if (check_is_digit(argv))
	{
		printf("Invalid arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 0)
	{
		printf("Can't test more than 200 philo or less that 0\n");
		return (1);
	}
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		printf("the time can't be less that 60\n");
		return (1);
	}
	return (0);
}
