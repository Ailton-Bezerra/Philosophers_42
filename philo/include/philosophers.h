/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:06:02 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/17 12:14:04 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


// a quantidade de garfos é a mesma que de filosofos

// esses são os argumentos que o programa recebe

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]

// time_to_die é contado em microssegundos
// este tempo começa a contar a partir do momento em que o programa começa, ou quando o philo come.

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

// as threads não são processos novos (não têm um PID), são como que fragmentos da thread principal (a main), e, surpreendentemente, compartilham o mesmo espaço de memória entre si, o que traz suas vantagens e seus desafios para que tudo funcione certinho.

// timestamps (quantidade de tempo que dura uma atividade)

// colocar a flag -pthread para compilar certas funções

// criar a rotina com funções para cada coisa (comer, dormir, pensar). O id do garfo de cada filosofo pode ser 
// igual ao id dos filosofos. Criar uma mutex com cada indexe dos garfos.

// usleep(100) no think.
//  /philo 5 800 400 400

// criar uma struct que vai servir para cada philo.
// algumas soluções usam a data dentro de philos,
//outras usam philo dentro de data.


// ========== defines ==========
# define TAKE_FORK "\001\033[1;33m\002has taken a fork\001\033[0m\002"
# define IS_DIED "\001\033[1;37m\002is  died\001\033[0m\002"
# define IS_SLEEP "\001\033[1;36m\002is  sleeping\001\033[0m\002"
# define IS_THINKING "\001\033[1;35m\002is  thinking\001\033[0m\002"
# define IS_EATING "\001\033[1;32m\002is  eating\001\033[0m\002"
// =============================

// ========== structs ==========
typedef struct s_data t_data;

typedef struct s_philo
{
	int		id;
	
	pthread_mutex_t		fork_left;
	pthread_mutex_t		fork_right;
	t_data				*data;
	pthread_t			thread;
	
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	must_eat;
}		t_philo;

typedef struct s_data
{
	unsigned int	number_of_philos;
	long long		start_time;
	t_philo 		*philo;
	pthread_mutex_t *forks;
	pthread_mutex_t	print_msg;
	int				finished;
}			t_data;
// ==============================

// ==========  utils.c ==========
unsigned int	ft_atou(char *str);
int				is_negative(int argc, char *argv[]);
void 			join_all(t_data *data, t_philo *philo);

// ========== free_and_errros.c ==========
void free_struct(t_data *data);
int check_input(int argc, char *argv[]);

// ========== init.c ==========
t_philo *init_philos(char *argv[], t_data *data);
t_data	*init_data(char *argv[]);

// ========== routine_utils.c ==========
void		sleeping(t_philo *philo);
void		think(t_philo *philo);
void		eat(t_philo *philo);
void		take_right_fork(t_philo *philo, pthread_mutex_t  *right_fork);
void		take_left_fork(t_philo *philo, pthread_mutex_t *left_fork);

#endif