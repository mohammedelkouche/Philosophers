/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habitual.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:32:40 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/07 17:18:08 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_function(t_philos *philo)
{
	// long long	begin;

	pthread_mutex_lock(&philo->fork);
	action_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->next->fork);
	action_print(philo, "has taken a fork");
	
	action_print(philo, "is eating");
	
	// begin = time_stamp();
	wait_action(time_stamp(), philo->args->time_eat);
	
	pthread_mutex_lock(&philo->ml_eat);
	philo->tlast_eat = time_stamp();
	pthread_mutex_unlock(&philo->ml_eat);
	
	pthread_mutex_lock(&philo->mt_count);
	philo->count_eat++;
	pthread_mutex_unlock(&philo->mt_count);
	
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	sleep_function(t_philos *philo)
{
	// long long	begin;

	pthread_mutex_lock(&philo->args->print);
	printf("%lld\t %d\tis sleeping\n", \
	time_stamp() - philo->args->init_time, philo->id);
	// begin = time_stamp();
	wait_action(time_stamp(), philo->args->time_sleep);
	pthread_mutex_unlock(&philo->args->print);
}

void	think_function(t_philos *philo)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%lld\t %d\tis thinking\n", \
	time_stamp() - philo->args->init_time, philo->id);
	pthread_mutex_unlock(&philo->args->print);
}

int	check_nb_eat(t_philos *head)
{
	t_philos	*tmp;
	int			i;

	i = 0;
	tmp = head;
	while (i < tmp->args->nb_philo)
	{
		pthread_mutex_lock(&tmp->mt_count);
		pthread_mutex_lock(&tmp->args->mt_eat);
		if (tmp->count_eat < tmp->args->nb_eat
			|| tmp->args->nb_eat == -1)
		{
			pthread_mutex_unlock(&tmp->mt_count);
			pthread_mutex_unlock(&tmp->args->mt_eat);
			return (0);
		}
		pthread_mutex_unlock(&tmp->mt_count);
		pthread_mutex_unlock(&tmp->args->mt_eat);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	check_is_dead(t_philos *philo, int i)
{

	long long	t;

	usleep(1000);
	pthread_mutex_lock(&philo->ml_eat);
	t = philo->tlast_eat;
	// printf("%lld\n", time_stamp() - t);
	pthread_mutex_unlock(&philo->ml_eat);
	while (i < philo->args->nb_philo)
	{
		if (check_nb_eat(philo))
		{
			free_all(philo);
			return (0);
		}
		if (time_stamp() - t > philo->args->time_die)
		{
			pthread_mutex_lock(&philo->args->print);
			printf("%lld\t|%d|\tdied\n", \
			time_stamp() - philo->args->init_time, philo->id);
			// pthread_mutex_unlock(&philo->args->print);
			free_all(philo);
			return (0);
		}
		philo = philo->next;
		i++;
	}
	return (1);
}

// void	check_is_dead(t_philos *philo)
// {
// 	t_philos	*tmp;
// 	int			i;

// 	tmp = philo;
// 	i = 0;
// 	while (1)
// 	{
// 		usleep(1000);
// 		// stay();
// 		i = 0;

// 		while (i < philo->args->nb_philo)
// 		{
// 			if (check_nb_eat(philo))
// 				return ;
// 			if (time_stamp() - tmp->tlast_eat > tmp->args->time_die)
// 			{
// 				pthread_mutex_lock(&tmp->print);
// 				printf("%lld\t %d\tdied\n", \
// 				time_stamp() - tmp->args->init_time, tmp->id);
// 				// pthread_mutex_unlock(&philo->print);
// 				return ;
// 			}
// 			tmp = tmp->next;
// 			i++;
// 		}
// 	}
// }


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