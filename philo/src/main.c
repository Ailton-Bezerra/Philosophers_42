/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:48 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/22 10:33:52 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	take_forks(t_philo *p, pthread_mutex_t *l_fork, pthread_mutex_t *r_fork)
{
	if (p->id % 2 == 0)
	{
		if (!take_left_fork(p, l_fork))
			return (pthread_mutex_unlock(l_fork), 0);
		if (!take_right_fork(p, r_fork))
		{
			pthread_mutex_unlock(l_fork);
			pthread_mutex_unlock(r_fork);
			return (0);
		}
	}
	else
	{
		if (!take_right_fork(p, r_fork))
			return (pthread_mutex_unlock(r_fork), 0);
		if (!take_left_fork(p, l_fork))
		{
			pthread_mutex_unlock(l_fork);
			pthread_mutex_unlock(r_fork);
			return (0);
		}
	}
	return (1);
}

void	*routine(void *philo)
{
	t_philo			*p;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	p = (t_philo *)philo;
	left_fork = &p->data->forks[p->id - 1];
	right_fork = &p->data->forks[p->id % p->data->number_of_philos];
	while (1)
	{
		if (!take_forks(p, left_fork, right_fork))
			break ;
		if (!eat(p, left_fork, right_fork))
			break ;
		if (!sleeping(p))
			break ;
		if (!think(p))
			break ;
		usleep(1000);
	}
	return (NULL);
}

void	monitor_routine(t_philo *p)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		i = 0;
		if (!simulation_status(p))
			break ;
		while (i < p->data->number_of_philos)
		{
			if (is_death(&p[i]))
				break ;
			i++;
		}
		usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	t_philo			*philos;
	t_data			*data;
	unsigned int	i;

	if (!check_input(argc, argv))
		return (1);
	data = init_data(argv);
	if (!data)
		return (1);
	philos = init_philos(argv, data);
	if (!philos)
		return (1);
	i = -1;
	while (++i < data->number_of_philos)
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
	monitor_routine(philos);
	join_all(data, philos);
	free_struct(data);
	return (0);
}
