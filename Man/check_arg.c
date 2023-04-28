/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:54:16 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/28 19:16:48 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '+')
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
		}
	}
	return (1);
}

int	check_value(t_info *philo)
{
	if (philo->nb_philo < 1 || philo->time_die < 1 || philo->time_eat < 1
		|| philo->time_sleep < 1 || philo->nb_philo > 200)
		return (0);
	if (philo->time_die < 60 || philo->time_eat < 60 || philo->time_sleep < 60
		|| philo->nb_philo > 200)
		return (0);
	return (1);
}
