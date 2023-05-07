/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:14:36 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/05 16:25:12 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_philos *philo)
{
	t_philos	*tmp;
	t_philos	*next;
	t_philos	*test;
	int			i;

	i = 0;
	test = philo;
	free(test->args);
	tmp = philo;
	while (i < tmp->args->nb_philo)
	{
		next = tmp->next;
		free(tmp);
		i++;
		tmp = next;
	}
}