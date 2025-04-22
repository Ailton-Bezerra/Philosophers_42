/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:50:03 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/22 13:17:15 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_struct(t_data *data, t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < data->number_of_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
	pthread_mutex_destroy(&data->print_msg);
	pthread_mutex_destroy(&data->end);
	pthread_mutex_destroy(&philos->meal_time);
	free(data);
	free(philos);
}

int	check_input(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid input. The program receive 5 or 6 arguments!\n");
		return (0);
	}
	if (is_negative(argc, argv))
	{
		printf("All values must be positive!\n");
		return (0);
	}
	if (!ft_atou(argv[1]) || (argv[5] && !ft_atou(argv[5])))
	{
		printf("Numbers of philos and meals must be more than 0!\n");
		return (0);
	}
	if (ft_atou(argv[1]) > 200)
	{
		printf("Numbers of philos must be less than or equal 200!\n");
		return (0);
	}
	return (1);
}
