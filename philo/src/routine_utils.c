/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:04:07 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/16 12:04:50 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// void died(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->print_msg);
// time = (now.tv_sec * 1000ll) + (now.tv_usec / 1000) - philo->data->start_time;
// 	printf("%ld philo%d is died", time, philo->id);
// 	pthread_mutex_unlock(&philo->data->print_msg);
// }

void sleep(t_philo *philo)
{
	struct timeval	now;
	long int time;
	
	pthread_mutex_lock(&philo->data->print_msg);
	time = (now.tv_sec * 1000ll) + (now.tv_usec / 1000) - philo->data->start_time;
	printf("%ld philo%d is sleeping", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
}

void think(t_philo *philo)
{
	struct timeval	now;
	long int time;
	
	pthread_mutex_lock(&philo->data->print_msg);
	time = (now.tv_sec * 1000ll) + (now.tv_usec / 1000) - philo->data->start_time;
	printf("%ld philo%d is thinking", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
}

void eat(t_philo *philo)
{
	struct timeval	now;
	long int time;
	
	pthread_mutex_lock(&philo->data->print_msg);
	time = (now.tv_sec * 1000ll) + (now.tv_usec / 1000) - philo->data->start_time;
	printf("%ld philo%d is eating", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
}

void take_right_fork(t_philo *philo, pthread_mutex_t  *right_fork)
{
	struct timeval	now;
	long int time;
	
	pthread_mutex_lock(right_fork);
	pthread_mutex_lock(&philo->data->print_msg);
	time = (now.tv_sec * 1000ll) + (now.tv_usec / 1000) - philo->data->start_time;
	printf("%ld philo%d has taken a fork", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
	pthread_mutex_unlock(right_fork);
}

void take_left_fork(t_philo *philo, pthread_mutex_t *left_fork)
{
	struct timeval	now;
	long int time;

	pthread_mutex_lock(left_fork);
	pthread_mutex_lock(&philo->data->print_msg);
	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000ll) + (now.tv_usec / 1000) - philo->data->start_time;
	printf("%ld philo%d has taken a fork", time, philo->id);
	pthread_mutex_unlock(&philo->data->print_msg);
	pthread_mutex_unlock(left_fork);
}
