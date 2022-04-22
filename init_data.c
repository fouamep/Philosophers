/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:59:42 by fbouanan          #+#    #+#             */
/*   Updated: 2022/04/18 16:59:44 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nbr_of_philos)
	{
		data[i].i = i;
		data[i].philo = philo;
		data[i].s_e = 0;
		data[i].is_e = 0;
		data[i].eat_times = 0;
		i++;
	}
}

int	init_data2(t_philo *philo, int ac, char **av)
{
	philo->nbr_of_philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		philo->nbr_to_eat = -1;
	else if (ac == 6)
		philo->nbr_to_eat = ft_atoi(av[5]);
	if (philo->nbr_of_philos <= 0)
		return (-1);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->nbr_of_philos);
	philo->thread = malloc(sizeof(pthread_t) * philo->nbr_of_philos);
	philo->ts = my_time(0);
	return (0);
}

void	creat_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->nbr_of_philos)
	{
		pthread_mutex_init(&(philo->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(philo->print), NULL);
	i = 0;
	while (i < philo->nbr_of_philos)
	{
		pthread_create(&philo->thread[i], NULL, &new_philo, &data[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < philo->nbr_of_philos)
	{
		pthread_create(&philo->thread[i], NULL, &new_philo, &data[i]);
		i += 2;
	}
}
