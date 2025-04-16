/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:48 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/16 12:05:23 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void *routine (void *philo)
{
	pthread_mutex_t  *left_fork;
	pthread_mutex_t  *right_fork;

	left_fork = &((t_philo *)philo)->data->forks[((t_philo *)philo)->id];
	right_fork = &((t_philo *)philo)->data->forks[(((t_philo *)philo)->id + 1) % ((t_philo *)philo)->data->number_of_philos];
	// while(nenhum philo morreu ou se alimentou o suficiente)
	take_left_fork(philo, left_fork);
	take_right_fork(philo, right_fork);
	eat(philo);
	sleep(philo);
	think(philo);
	return ("test finish");
}

int main(int argc, char *argv[])
{
	t_philo philos;
	t_data	data;
	unsigned int i;
	
	if (!check_input(argc, argv))
		return (1);
	init_data(&data, argv);
	init_philos(&philos, argv);
	i = 0; 
	while (i < data.number_of_philos)
	{
		pthread_create(&data.philo[i].thread, NULL, &routine, &data.philo[i]);
		i++;
	}
	join_all(&data);
	free_struct(&data);
	return (0);
}
