/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:28:40 by fbouanan          #+#    #+#             */
/*   Updated: 2022/04/09 22:50:27 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	long			ts;
	int				nbr_of_philos;
	int				time_to_sleep;
	int				time_to_think;
	int				time_to_die;
	int				time_to_eat;
	int				nbr_to_eat;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_philo;

typedef struct s_data
{
	int		eat_times;
	int		is_e;
	long	s_e;
	int		i;
	t_philo	*philo;
}	t_data;

long	my_time(long start);
void	creat_threads(t_philo *philo, t_data *data);
void	init_data(t_data *data, t_philo *philo);
void	*check_death(t_data *data);
void	*new_philo(void *data);
void	ft_usleep(int time);
int		init_data2(t_philo *philo, int ac, char **av);
int		check_args(char *str);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
#endif
