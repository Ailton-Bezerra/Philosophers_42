/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:48 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/17 12:31:27 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &((t_philo *)philo)->data->forks[((t_philo *)philo)->id - 1];
	right_fork = &((t_philo *)philo)->data->forks[(((t_philo *)philo)->id - 1)
		% ((t_philo *)philo)->data->number_of_philos];
	// while(nenhum philo morreu ou se alimentou o suficiente)
	while (((t_philo *)philo)->must_eat)
	{
		take_left_fork(philo, left_fork);
		take_right_fork(philo, right_fork);
		eat(philo);
		sleeping(philo);
		think(philo);
		usleep(1000);
		((t_philo *)philo)->must_eat--;
	}
	return ("test");
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
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
		i++;
	}
	join_all(data, philos);
	free_struct(data);
	return (0);
}
