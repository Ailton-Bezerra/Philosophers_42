/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:04:07 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/21 16:36:23 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	sleeping(t_philo *philo)
{
	long long		time;

	if (!simulation_status(philo))
		return (0);
	pthread_mutex_lock(&philo->data->print_msg);
	time = current_time(philo);
	printf("%lld\t%d\t"IS_SLEEP"\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
	usleep(philo->time_to_sleep * 1000);
	return (1);
}

int	think(t_philo *philo)
{
	long long		time;

	if (!simulation_status(philo))
		return (0);
	pthread_mutex_lock(&philo->data->print_msg);
	time = current_time(philo);
	printf("%lld\t%d\t"IS_THINKING"\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
	usleep(1000);
	return (1);
}

int	eat(t_philo *p, pthread_mutex_t *l_fork, pthread_mutex_t *r_fork)
{
	long long		time;

	if (!simulation_status(p))
		return (0);
	pthread_mutex_lock(&p->data->print_msg);
	time = current_time(p);
	printf("%lld\t%d\t"IS_EATING"\n", time, p->id);
	pthread_mutex_unlock(&p->data->print_msg);
	pthread_mutex_lock(&p->meal_time);
	p->last_meal = time;
	pthread_mutex_unlock(&p->meal_time);
	usleep(p->time_to_eat * 1000);
	pthread_mutex_unlock(l_fork);
	pthread_mutex_unlock(r_fork);
	p->meals_eaten++;
	pthread_mutex_lock(&p->data->end);
	if (p->meals_eaten == p->must_eat)
		p->data->finished++;
	pthread_mutex_unlock(&p->data->end);
	return (1);
}

int	take_right_fork(t_philo *philo, pthread_mutex_t *right_fork)
{
	long long		time;

	pthread_mutex_lock(right_fork);
	if (!simulation_status(philo))
		return (pthread_mutex_unlock(right_fork), 0);
	pthread_mutex_lock(&philo->data->print_msg);
	time = current_time(philo);
	printf("%lld\t%d\t"TAKE_FORK"\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
	if (philo->data->number_of_philos == 1)
		return (pthread_mutex_unlock(right_fork), 0);
	return (1);
}

int	take_left_fork(t_philo *p, pthread_mutex_t *left_fork)
{
	long long		time;

	pthread_mutex_lock(left_fork);
	if (!simulation_status(p))
		return (pthread_mutex_unlock(left_fork), 0);
	pthread_mutex_lock(&p->data->print_msg);
	time = current_time(p);
	printf("%lld\t%d\t"TAKE_FORK"\n", time, p->id);
	pthread_mutex_unlock(&p->data->print_msg);
	return (1);
}
