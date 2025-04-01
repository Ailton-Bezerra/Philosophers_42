/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:06:02 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/01 15:56:47 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILISOPHERS_H
# define PHILOSOPHERS_H

// a quantidade de garfos é a mesma que de filosofos

// esses são os argumentos que o programa recebe
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]

// time_to_die é contado em milisegundos
// este tempo é começa a contar a partir do momento em que o programa começa, ou quando o philo come.

// time_to_eat é o tempo que leva para um philo comer
// durante esse tempo, dois garfos estarão ocupados (ou seja, é o tempo em que o recurso ficara bloqueado).

// time_to_sleep é o tempo em que o philo passa dormindo.

// number_of_times_each_philosopher_must_eat é opcional. é a quantidade minima de vezes que cada philo
// deve comer, se não for especificado, o programa termina quando um philo morre.

// o id dos philos começa em 1 e vai até a quantidade passada como argumento.

// é possivel fazer uma lista circular para visualizar melhor a abstração da mesa, mas da para
// fazer um array, pensando que o ultimo indice do array de philos se senta ao lado do primeiro e
// vice versa

// criar um timestamp (timestamp_in_ms X has taken a fork) que represente o tempo atual da simulação
// (x é o id do philo)

// A message announcing a philosopher died should be displayed no more than 10 ms
// after the actual death of the philosopher.

// não pode usar exit no mandatorio
// cada philo tem que ser uma thread
// cada garfo tem que ter uma mutex

enum e_action
{
	EATING,
	THINGING,
	SLEEPING,
	DIED,
};

typedef struct s_forks
{
	void	*fork_array;
}				t_forks;

typedef struct s_philo
{
	int		id;
	int		fork_left;
	int		fork_right;
}		t_philo;

typedef struct s_table
{
	t_philo *philo;
	t_forks *forks;
}			t_table;

#endif