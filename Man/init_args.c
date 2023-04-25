/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:03:31 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/25 17:13:41 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_args(t_philosophers *init, int ac, char **av)
{
	init->nb_philo = ft_atoi(av[1]);
	init->time_die = ft_atoi(av[2]);
	init->time_eat = ft_atoi(av[3]);
	init->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		init->nb_eat = ft_atoi(av[5]);
		if (init->nb_philo < 0 || init->time_die < 0 || init->time_eat < 0
			|| init->time_sleep < 0 || init->nb_eat < 0)
			return (0);
	}
	else
	{
		init->nb_eat = -1;
		if (init->nb_philo < 0 || init->time_die < 0 || init->time_eat < 0
			|| init->time_sleep < 0)
			return (0);
	}
	return (1);
}
