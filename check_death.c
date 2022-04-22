/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:41:25 by fbouanan          #+#    #+#             */
/*   Updated: 2022/04/14 20:41:33 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eating_times(t_data *data)
{
	int	j;

	j = 0;
	if (data->philo->nbr_to_eat == -1)
		return (0);
	while (j < data->philo->nbr_of_philos)
	{
		if (data[j].eat_times < data->philo->nbr_to_eat)
			break ;
		j++;
	}
	if (j == data->philo->nbr_of_philos)
		return (1);
	return (0);
}

void	*check_death(t_data *dt)
{
	int		i;
	long	k;

	k = my_time(dt[0].philo->ts);
	i = 0;
	while (1)
	{
		if (dt[i].is_e == 0 && (int)(k - dt[i].s_e) >= dt[0].philo->time_to_die)
		{
			pthread_mutex_lock(&dt->philo->print);
			printf("%04ld philo %d died\n", my_time(dt[0].philo->ts), i + 1);
			return (0);
		}
		i = (i + 1) % dt->philo->nbr_of_philos;
		k = my_time(dt[0].philo->ts);
		if (check_eating_times(dt) == 1)
		{
			pthread_mutex_lock(&dt->philo->print);
			return (0);
		}
		usleep(10);
	}
	return (0);
}
