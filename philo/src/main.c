/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:48 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/02 18:22:47 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void init_philos(t_philo *philos, char *argv[])
{
	philos->time_to_die = ft_atou(argv[2]);
	philos->time_to_eat =ft_atou(argv[3]);
	philos->time_to_sleep = ft_atou(argv[4]);
	philos->must_eat = 0;
	if (argv[5])
		philos->must_eat = ft_atou(argv[5]);
}

void	init_data(t_data *data, char *argv[])
{
	struct timeval	start;
	int				i;

	gettimeofday(&start, NULL);
	i = 0;
	data->number_of_philos = ft_atou(argv[1]);
	data->start_time = (start.tv_sec * 1000 + start.tv_usec) / 1000;
	data->finished = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	while (i < data->number_of_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init()
}

int main(int argc, char *argv[])
{
	t_philo philos;
	t_data	data;	
	
	if (argc < 5 || argc > 6)
		printf("Invalid input\n");
	init_data(&data, argv);
	init_philos(&philos, argv);
}
