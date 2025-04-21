/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:41:23 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/21 16:16:22 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_philo	*init_philos(char *argv[], t_data *data)
{
	unsigned int	i;
	t_philo			*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->number_of_philos);
	if (!philos)
		return (NULL);
	while (i < data->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].time_to_die = ft_atou(argv[2]);
		philos[i].time_to_eat = ft_atou(argv[3]);
		philos[i].time_to_sleep = ft_atou(argv[4]);
		philos[i].must_eat = 0;
		if (argv[5])
			philos[i].must_eat = ft_atou(argv[5]);
		philos[i].last_meal = 0;
		philos[i].meals_eaten = 0;
		pthread_mutex_init(&philos[i].meal_time, NULL);
		philos[i++].data = data;
	}
	return (philos);
}

t_data	*init_data(char *argv[])
{
	struct timeval	start;
	unsigned int	i;
	t_data			*data;

	if (!argv[0])
		return (NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	gettimeofday(&start, NULL);
	i = 0;
	data->number_of_philos = ft_atou(argv[1]);
	data->start_time = start.tv_sec * 1000LL + start.tv_usec / 1000;
	data->finished = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	data->end_of_simulation = 0;
	while (i < data->number_of_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->print_msg, NULL);
	pthread_mutex_init(&data->end, NULL);
	return (data);
}
