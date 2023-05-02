/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:03:31 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/02 17:59:09 by mel-kouc         ###   ########.fr       */
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

	philo =  (t_philos *)ptr;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		eat_function(philo);
		sleep_function(philo);
		think_function(philo);
		// if (!checl_is_dead(philo))
		// 	break ;
	}
	return (NULL);
}

void	init_thread(t_philos *head, t_info *info)
{
	t_philos	*tmp;
	int			i;

	i = -1;
	tmp = head;
	info->init_time = time_stamp();
	while (++i < info->nb_philo)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_create(&tmp->thread, NULL, &procedure, tmp);
		tmp = tmp->next;
	}
	i = -1;
	while (++i < info->nb_philo)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	}
	head->count_eat = 0;
}


