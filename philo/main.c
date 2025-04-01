/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:48 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/01 15:43:36 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// função para setar os argumentos;
void set_args(char *argv[])
{
	number_of_philosophers = argv[1];
	time_to_die = argv[2];
	time_to_eat = argv[3];
	time_to_sleep = argv[4];
	number_of_times_each_philosopher_must_eat = argv[5] // caso seja passado;
}

int main(int argc, char *argv[])
{
	// o programa tem que receber 5 argumentos;
	if (argc < 5 || argc > 6)
		error;
	
}