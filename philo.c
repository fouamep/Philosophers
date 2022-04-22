/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:50:15 by fbouanan          #+#    #+#             */
/*   Updated: 2022/04/09 22:50:21 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_errors(int ac, char **av)
{
	int	i;

	i = ac;
	while (i > 0)
	{
		if (check_args(av[i]) == -1)
		{
			return (1);
		}
		i--;
	}
	return (0);
}

static void	rest_new_p(t_philo *philo, int id, t_data *dt)
{
	pthread_mutex_lock(&philo->forks[id]);
	pthread_mutex_lock(&philo->print);
	printf("%04ld %d has taken a fork\n", my_time(philo->ts), id + 1);
	pthread_mutex_unlock(&philo->print);
	id = (dt->i + 1) % dt->philo->nbr_of_philos;
	pthread_mutex_lock(&philo->forks[id]);
	pthread_mutex_lock(&philo->print);
	printf("%04ld %d has taken a fork\n", my_time(philo->ts), dt->i + 1);
	pthread_mutex_unlock(&philo->print);
	dt->s_e = my_time(philo->ts);
	dt->is_e = 1;
	pthread_mutex_lock(&philo->print);
	printf("%04ld %d is eating\n", my_time(philo->ts), dt->i + 1);
	pthread_mutex_unlock(&philo->print);
}

void	*new_philo(void *data)
{
	t_philo	*philo;
	t_data	*dt;
	int		id;

	dt = (t_data *)data;
	philo = dt->philo;
	while (1)
	{
		id = dt->i;
		rest_new_p(philo, id, dt);
		ft_usleep(philo->time_to_eat * 1000);
		dt->eat_times++;
		pthread_mutex_unlock(&philo->forks[dt->i]);
		id = (dt->i + 1) % dt->philo->nbr_of_philos;
		pthread_mutex_unlock(&philo->forks[id]);
		dt->is_e = 0;
		pthread_mutex_lock(&philo->print);
		printf("%04ld %d is sleeping\n", my_time(philo->ts), dt->i + 1);
		pthread_mutex_unlock(&philo->print);
		ft_usleep(philo->time_to_sleep * 1000);
		pthread_mutex_lock(&philo->print);
		printf("%04ld %d is thiking\n", my_time(philo->ts), dt->i + 1);
		pthread_mutex_unlock(&philo->print);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_philo		*philo;

	if (ac == 5 || ac == 6)
	{
		if (check_errors(ac - 1, av) == 1)
			return (1);
		philo = malloc(sizeof(t_philo));
		if (init_data2(philo, ac, av) == -1)
			return (0);
		data = malloc(sizeof(t_data) * philo->nbr_of_philos);
		init_data(data, philo);
		creat_threads(philo, data);
		check_death(data);
		return (0);
	}
	write(2, "Error: Number of args\n", 22);
	return (1);
}
