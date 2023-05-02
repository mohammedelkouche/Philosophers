/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habitual.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:32:40 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/02 17:59:12 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_function(t_philos *philo)
{
	long long	begin;

	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->print);
	printf("%lld\t %d\thas taken a fork\n", \
	time_stamp() - philo->args->init_time, philo->id);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(&philo->print);
	printf("%lld\t %d\thas taken a fork\n", \
	time_stamp() - philo->args->init_time, philo->id);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->print);
	printf("%lld\t %d\tis eating\n", \
	time_stamp() - philo->args->init_time, philo->id);
	begin = time_stamp();
	wait_action(begin, philo->args->time_eat);
	philo->tlast_eat = time_stamp();
	philo->count_eat++;
	pthread_mutex_unlock(&philo->print);
	// usleep(philo->args->time_eat * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	sleep_function(t_philos *philo)
{
	long long	begin;

	printf("%lld\t %d\tis sleeping\n", \
	time_stamp() - philo->args->init_time, philo->id);
	begin = time_stamp();
	wait_action(begin, philo->args->time_sleep);
	// usleep(philo->args->time_sleep * 1000);
}

void	think_function(t_philos *philo)
{
	printf("%lld\t %d\tis thinking\n", \
	time_stamp() - philo->args->init_time, philo->id);
}

// int	checl_is_dead(t_philos *philo)
// {
// 	if (philo->count_eat == philo->args->nb_eat)
// 		return (0);
// 	if (time_stamp - philo->tlast_eat > philo->args->time_die)
// 		return (0);
// 	return (1);
// }
