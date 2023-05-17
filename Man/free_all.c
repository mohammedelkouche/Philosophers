/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:14:36 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/17 15:58:09 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_philos *philo, t_info *info)
{
	t_philos	*tmp;
	t_philos	*next;

	tmp = philo;
	pthread_mutex_destroy(&tmp->args->mt_eat);
	pthread_mutex_destroy(&tmp->args->print);
	free(info);
	while (tmp)
	{
		pthread_mutex_lock(&tmp->ml_eat);
		pthread_mutex_destroy(&tmp->ml_eat);
		pthread_mutex_destroy(&tmp->mt_count);
		pthread_mutex_destroy(&tmp->fork);
		next = tmp->next;
		free(tmp);
		if (next->id == 1)
			break ;
		tmp = next;
	}
}
