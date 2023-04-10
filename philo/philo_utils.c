/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:58:50 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/11 00:01:58 by kalshaer         ###   ########.fr       */
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