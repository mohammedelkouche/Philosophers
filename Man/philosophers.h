/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:14:49 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/27 18:06:41 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philosophers {
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_eat;
}	t_philosophers;

typedef struct s_attribute {
	int			id;
	pthread_t	thread;
}	t_attribute;

int		ft_atoi(char *str);
int		init_args(t_philosophers *philo, int ac, char **av);
int		check_arg(int argc, char **argv);


#endif