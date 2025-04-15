/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:40:33 by ailbezer          #+#    #+#             */
/*   Updated: 2025/04/15 10:40:46 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

unsigned int ft_atou(char *str)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	if (str[i] && str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		nb = (nb * 10) + str[i++] - '0';
	return (nb);
}

int is_negative(int argc, char *argv[])
{
	int i;

	i = 1;
	while(argv[i] && i <= argc)
	{
		if (argv[i][0] == '-')
			return (1);
		i++;
	}
	return (0);
}
