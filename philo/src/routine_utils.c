/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:04:07 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/17 12:34:04 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// void died(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->print_msg);
// time = (now.tv_sec * 1000ll + now.tv_usec / 1000) - philo->data->start_time;
// 	printf("%ld p%d"IS_DIED"\n", time, philo->id);
// 	pthread_mutex_unlock(&philo->data->print_msg);
// }

void	sleeping(t_philo *philo)
{
	struct timeval	now;
	long long		time;

	pthread_mutex_lock(&philo->data->print_msg);
	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000ll + now.tv_usec / 1000) - philo->data->start_time;
	printf("%lld p%d "IS_SLEEP"\n", time, philo->id);
	usleep(philo->time_to_sleep);
	pthread_mutex_unlock(&philo->data->print_msg);
}

void	think(t_philo *philo)
{
	struct timeval	now;
	long long		time;

	pthread_mutex_lock(&philo->data->print_msg);
	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000ll + now.tv_usec / 1000) - philo->data->start_time;
	printf("%lld p%d "IS_THINKING"\n", time, philo->id);
	usleep(1000);
	pthread_mutex_unlock(&philo->data->print_msg);
}

void	eat(t_philo *philo)
{
	struct timeval	now;
	long long		time;

	pthread_mutex_lock(&philo->data->print_msg);
	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000ll + now.tv_usec / 1000) - philo->data->start_time;
	printf("%lld p%d "IS_EATING"\n", time, philo->id);
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->data->print_msg);
}

void	take_right_fork(t_philo *philo, pthread_mutex_t *right_fork)
{
	struct timeval	now;
	long long		time;

	pthread_mutex_lock(right_fork);
	pthread_mutex_lock(&philo->data->print_msg);
	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000LL + now.tv_usec / 1000) - philo->data->start_time;
	printf("%lld p%d " TAKE_FORK"\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
	pthread_mutex_unlock(right_fork);
}

void	take_left_fork(t_philo *philo, pthread_mutex_t *left_fork)
{
	struct timeval	now;
	long long		time;

	pthread_mutex_lock(left_fork);
	pthread_mutex_lock(&philo->data->print_msg);
	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000ll + now.tv_usec / 1000) - philo->data->start_time;
	printf("%lld p%d " TAKE_FORK"\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
	pthread_mutex_unlock(left_fork);
}
