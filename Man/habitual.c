/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habitual.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:32:40 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/11 21:54:35 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_function(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork);
	action_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->next->fork);
	action_print(philo, "has taken a fork");
	action_print(philo, "is eating");
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
	action_print(philo, "is sleeping");
	wait_action(time_stamp(), philo->args->time_sleep);
}

void	think_function(t_philos *philo)
{
	action_print(philo, "is thinking");
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

	while (i < philo->args->nb_philo)
	{
		usleep(1000);
		if (check_nb_eat(philo))
		{
			free_all(philo);
			return (0);
		}
		pthread_mutex_lock(&philo->ml_eat);
		t = philo->tlast_eat;
		pthread_mutex_unlock(&philo->ml_eat);
		if (time_stamp() - t > philo->args->time_die)
		{
			pthread_mutex_lock(&philo->args->print);
			printf("%lld\t %d\tdied\n", \
			time_stamp() - philo->args->init_time, philo->id);
			free_all(philo);
			return (0);
		}
		philo = philo->next;
		i++;
	}
	return (1);
}
