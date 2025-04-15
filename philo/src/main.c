/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:48 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/15 10:41:43 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int main(int argc, char *argv[])
{
	t_philo philos;
	t_data	data;	
	
	if (!check_input(argc, argv))
		return (1);
	init_data(&data, argv);
	init_philos(&philos, argv);
	// rotina
	
	
	
	// join threads
	// destroy mutex
	free_struct(&data);
	return (0);
}
