/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:06:02 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/21 16:03:23 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

// ========== defines ==========
# define TAKE_FORK "\001\033[1;33m\002has taken a fork\001\033[0m\002"
# define IS_DIED "\001\033[1;31m\002died\001\033[0m\002"
# define IS_SLEEP "\001\033[1;36m\002is  sleeping\001\033[0m\002"
# define IS_THINKING "\001\033[1;35m\002is  thinking\001\033[0m\002"
# define IS_EATING "\001\033[1;32m\002is  eating\001\033[0m\002"
// =============================

// ========== structs ==========
typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	t_data				*data;
	pthread_t			thread;
	pthread_mutex_t		meal_time;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		must_eat;
	long long			last_meal;
}						t_philo;

typedef struct s_data
{
	unsigned int	number_of_philos;
	long long		start_time;
	int				end_of_simulation;
	pthread_mutex_t	end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_msg;
	int				finished;
}					t_data;
// ==============================

// ==========  utils.c ==========
unsigned int	ft_atou(char *str);
int				is_negative(int argc, char *argv[]);
void			join_all(t_data *data, t_philo *philo);
long			current_time(t_philo *philo);

// ========== free_and_errros.c ==========
void			free_struct(t_data *data);
int				check_input(int argc, char *argv[]);

// ========== init.c ==========
t_philo			*init_philos(char *argv[], t_data *data);
t_data			*init_data(char *argv[]);

// ========== routine_utils.c ==========
int				sleeping(t_philo *philo);
int				think(t_philo *philo);
int				eat(t_philo *philo, pthread_mutex_t *left_fork,
					pthread_mutex_t *right_fork);
int				take_right_fork(t_philo *philo, pthread_mutex_t *right_fork);
int				take_left_fork(t_philo *philo, pthread_mutex_t *left_fork);

// ========== monitor_utils.c ==========
int				simulation_status(t_philo *philo);
int				is_death(t_philo *p);

#endif