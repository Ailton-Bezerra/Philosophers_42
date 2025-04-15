/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:50:03 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/15 10:40:38 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void free_struct(t_data *data)
{
	free(data->forks);	
}

int check_input(int argc, char *argv[])
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
	if (!ft_atou(argv[1]))
	{
		printf("Numbers of philos must be more than 0!\n");
		return (0);
	}
	if (ft_atou(argv[1]) > 200)
	{
		printf("Numbers of philos must be less than or equal 200!\n");
		return (0);
	}
	return (1);
}
