/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:50:55 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/04 21:28:03 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

t_philos	*ft_lstlast(t_philos *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_philos	*ft_lstnew(int id, t_info *info)
{
	t_philos	*new_node;

	new_node = (t_philos *)malloc(sizeof(t_philos));
	if (!new_node)
		return (NULL);
	new_node->id = id;
	new_node->args = info;
	new_node->next = NULL;
	new_node->count_eat = 0;
	return (new_node);
}


void	ft_lst_addback(t_philos **head, t_philos *new)
{
	t_philos	*last;

	if (!head || !new)
		return ;
	else if (*head == 0)
		*head = new;
	else
	{
		last = ft_lstlast(*head);
		last->next = new;
	}
}

void	wait_action(long long begin, int action)
{
	while (time_stamp() - begin < action)
		usleep(1);
}

long long	time_stamp(void)
{
	long long			time;
	struct timeval		currant_time;

	gettimeofday(&currant_time, NULL);
	time = ((currant_time.tv_sec * 1000) + (currant_time.tv_usec / 1000));
	return (time);
}
