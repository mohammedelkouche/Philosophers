/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:03:31 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/30 18:01:44 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_args(t_info *info, int ac, char **av)
{
	info->nb_philo = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->nb_eat = ft_atoi(av[5]);
	else
		info->nb_eat = -1;
	if (!check_value(info))
		return (0);
	return (1);
}

void	*procedure(void *ptr)
{
	t_philos	*philo;

	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		eat_function(philo);
		sleep_function();
		think_function();
	}
}

void	init_thread(t_philos *head, t_info *info)
{
	t_philos	*tmp;
	int			i;

	i = -1;
	tmp = head;
	while (++i < info->nb_philo)
	{
		pthread_mutex_init(tmp->fork, NULL);
		pthread_create(&tmp->thread, NULL, &procedure, NULL);
		tmp = tmp->next;
	}
}
