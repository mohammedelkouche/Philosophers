/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habitual.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:32:40 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/04 16:49:17 by mel-kouc         ###   ########.fr       */
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

int	check_nb_eat(t_philos *head)
{
	t_philos	*tmp;
	int			i;

	i = 0;
	tmp = head;
	while (i < tmp->args->nb_philo)
	{
		if (tmp->count_eat < tmp->args->nb_eat
			|| tmp->args->nb_eat == -1)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	check_is_dead(t_philos *philo)
{
	t_philos	*tmp;
	int			i;

	tmp = philo;
	i = 0;
	while (1)
	{	
		usleep(1000);
		i = 0;
	
		while (i < philo->args->nb_philo)
		{
			// if (tmp->count_eat == tmp->args->nb_eat)
			if (check_nb_eat(philo))
				return ;
			// 	return ;
			if (time_stamp() - tmp->tlast_eat > tmp->args->time_die)
			{
				pthread_mutex_lock(&tmp->print);
				printf("%lld\t %d\tdied\n", \
				time_stamp() - tmp->args->init_time, tmp->id);
				// pthread_mutex_unlock(&philo->print);
				return ;
			}
			tmp = tmp->next;
			i++;
		}
	}
}


// int	check_is_dead(t_philos *philo)
// {
// 	t_philos	*tmp;
// 	int			i;

// 	i = 0;
// 	tmp = philo;
// 	while (i < philo->args->nb_philo)
// 	{
// 		if (philo->count_eat == philo->args->nb_eat)
// 			return (0);
// 		if (time_stamp() - philo->tlast_eat > philo->args->time_die)
// 		{
// 			pthread_mutex_lock(&philo->print);
// 			printf("%lld\t %d\tdied\n", \
// 			time_stamp() - philo->args->init_time, philo->id);
// 			// pthread_mutex_unlock(&philo->print);
// 			return (0);
// 		}
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }