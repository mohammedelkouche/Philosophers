/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:14:49 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/28 19:19:56 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>

// struct	s_attribute;

typedef struct s_info {
	int					nb_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
}	t_info;

typedef struct s_philos {
	int				id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct t_info	*args;
	struct s_philos	*next;
}	t_philos;

int		ft_atoi(char *str);
int		init_args(t_info *philo, int ac, char **av);
int		check_arg(char **argv);
int		check_value(t_info *philo);

#endif