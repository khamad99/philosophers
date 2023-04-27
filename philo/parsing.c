/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:48:34 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/19 18:02:15 by kalshaer         ###   ########.fr       */
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
	while(argv[++i])
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
	return (0);
}
