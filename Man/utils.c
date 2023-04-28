/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:50:55 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/28 19:18:43 by mel-kouc         ###   ########.fr       */
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

// s_philos	*ft_lstnew(int id, t_info *args)
// {
// 	s_philos	*new_node;

// 	new_node = (s_philos *)malloc(sizeof(s_philos));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->id = id;
// 	new_node->args =args;
// 	new_node->next = NULL; //new_node->next = new_node
// 	return (new_node);
// }
