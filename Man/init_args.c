/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:03:31 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/07 17:04:34 by mel-kouc         ###   ########.fr       */
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

	philo = (t_philos *)ptr;
	pthread_mutex_lock(&philo->ml_eat);
	philo->tlast_eat = time_stamp();
	pthread_mutex_unlock(&philo->ml_eat);
	if (philo->id % 2 == 0)
		usleep(philo->args->time_eat * 1000);
	while (1)
	{
		eat_function(philo);
		sleep_function(philo);
		think_function(philo);
	}
	return (NULL);
}

void	init_thread(t_philos *head, t_info *info)
{
	t_philos	*tmp;
	int			i;

	i = -1;
	tmp = head;

	tmp->args->init_time = time_stamp();
	pthread_mutex_init(&tmp->args->mt_eat, NULL);
	pthread_mutex_init(&tmp->args->print, NULL);

	while (++i < info->nb_philo)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_mutex_init(&tmp->mt_count, NULL);
		pthread_mutex_init(&tmp->ml_eat, NULL);
		pthread_create(&tmp->thread, NULL, &procedure, tmp);
		pthread_detach(tmp->thread);
		tmp = tmp->next;
	}
	// i = -1;
	// while (++i < info->nb_philo)
	// {
	// 	pthread_detach(tmp->thread);
	// 	tmp = tmp->next;
	// }
	while (1)
	{
		i = 0;
		if (!check_is_dead(head, i))
			break ;
	}
}


