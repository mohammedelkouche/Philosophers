/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:14:49 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/17 15:58:49 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_info {
	int					nb_philo;
	int					time_die;
	int					time_eat;
	long long			init_time;
	int					time_sleep;
	pthread_mutex_t		mt_eat;
	int					nb_eat;
	pthread_mutex_t		print;
}	t_info;

typedef struct s_philos {
	int				id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct s_info	*args;
	struct s_philos	*next;
	int				count_eat;
	pthread_mutex_t	mt_count;
	long long		tlast_eat;
	pthread_mutex_t	ml_eat;
}	t_philos;

int			ft_atoi(char *str);
int			init_args(t_info *info, int ac, char **av);
int			check_arg(char **argv);
int			check_value(t_info *philo);
t_philos	*create_list(t_philos *head, t_info *info);
t_philos	*ft_lstnew(int id, t_info *info);
void		ft_lst_addback(t_philos **head, t_philos *new);
t_philos	*ft_lstlast(t_philos *lst);
void		init_thread(t_philos *head, t_info *info);
void		*procedure(void *ptr);
void		eat_function(t_philos *philo);
void		sleep_function(t_philos *philo);
void		think_function(t_philos *philo);
long long	time_stamp(void);
void		action_print(t_philos *philo, char *str);
void		wait_action(long long begin, int action);
int			check_is_dead(t_philos *philo, int i, t_info *info);
int			check_nb_eat(t_philos *head);
void		stay(void);
void		free_all(t_philos *philo, t_info *info);

#endif