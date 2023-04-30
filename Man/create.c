/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:24:18 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/30 15:17:54 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

t_philos	*create_list(t_philos *head, t_info *info)
{
	int	i;

	i = 1;
	while (i <= info->nb_philo)
	{
		ft_lst_addback(&head, ft_lstnew(i, info));
		i++;
	}
	ft_lstlast(head)->next = head;
	return (head);
}
