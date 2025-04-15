/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:48 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/15 10:15:09 by ailbezer         ###   ########.fr       */
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
	unsigned int	i;

	if (!argv[0])
		return ;
	gettimeofday(&start, NULL);
	i = 0;
	data->number_of_philos = ft_atou(argv[1]);
	data->start_time = (start.tv_sec * 1000ll) + (start.tv_usec / 1000);
	printf("start_time: %u\n", data->start_time);
	data->finished = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	while (i < data->number_of_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	// pthread_mutex_init()
}

static  int check_input(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid input. The program receive 5 or 6 arguments\n");
		return (0);
	}
	if (!ft_atou(argv[1]))
	{
		printf("Numbers of philos must be more than 0\n");
		return (0);
	}
	if (ft_atou(argv[1]) > 200)
	{
		printf("Numbers of philos must be less than or equal 200\n");
		return (0);
	}
	return (1);
}

int main(int argc, char *argv[])
{
	t_philo philos;
	t_data	data;	
	
	if (!check_input(argc, argv))
		return (1);
	init_data(&data, argv);
	init_philos(&philos, argv);

	// join threads
	// destroy mutex
	free_struct(&data);
	return (0);
}
