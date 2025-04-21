/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:06:57 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/21 17:04:15 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	simulation_status(t_philo *philo)
{
	int				end;
	unsigned int	finished;

	pthread_mutex_lock(&philo->data->end);
	end = philo->data->end_of_simulation;
	finished = philo->data->finished;
	pthread_mutex_unlock(&philo->data->end);
	if (end || finished == philo->data->number_of_philos)
		return (0);
	return (1);
}

int	is_death(t_philo *p)
{
	long		last_meal;
	long long	time;

	time = current_time(p);
	pthread_mutex_lock(&p->meal_time);
	last_meal = p->last_meal;
	pthread_mutex_unlock(&p->meal_time);
	if (current_time(p) - last_meal > p->time_to_die)
	{
		pthread_mutex_lock(&p->data->print_msg);
		printf("%lld\t%d\t"IS_DIED"\n", time, p->id);
		pthread_mutex_unlock(&p->data->print_msg);
		pthread_mutex_lock(&p->data->end);
		p->data->end_of_simulation = 1;
		pthread_mutex_unlock(&p->data->end);
		return (1);
	}
	return (0);
}
