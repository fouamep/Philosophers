/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:50:34 by fbouanan          #+#    #+#             */
/*   Updated: 2022/04/09 22:50:35 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char *str)
{
	long	i;

	i = 0;
	if (!str)
	{
		write(2, "error\n", 6);
		return (-1);
	}
	if (str[i] == '\0')
	{
		write(2, "Error: Invalid Input\n", 21);
		return (-1);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			write(2, "Error: Invalid Input\n", 21);
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	check(size_t i)
{
	if (i == 1)
		return (-1);
	return (0);
}

int	ft_atoi(char *str)
{
	size_t				k;
	size_t				i;
	int					sin;
	unsigned long long	n;

	i = 0;
	n = 0;
	sin = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sin = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	k = i;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - 48);
	k = i - k;
	if (k > 19 || n > 9223372036854775807)
		return (check(sin));
	n = n * sin;
	return ((int)n);
}

long	my_time(long start)
{
	struct timeval	tv;
	long			holder;

	gettimeofday(&tv, NULL);
	holder = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (holder - start);
}

void	ft_usleep(int time)
{
	long	old;

	old = my_time(0);
	time = time / 1000;
	while (my_time(old) < time)
		usleep(100);
}
