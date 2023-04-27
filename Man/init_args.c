/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:03:31 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/27 10:26:15 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_args(t_philosophers *philo, int ac, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_die = ft_atoi(av[2]);
	philo->time_eat = ft_atoi(av[3]);
	philo->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_eat = ft_atoi(av[5]);
	else
		philo->nb_eat = -1;
	if (philo->nb_philo <= 0 || philo->time_die <= 0 || philo->time_eat <= 0
		|| philo->time_sleep <= 0 || philo->nb_philo > 200)
		return (0);
	return (1);
}
