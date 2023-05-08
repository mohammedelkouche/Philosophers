/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:21:23 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/08 18:50:44 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_action(long long begin, int action)
{
	while (time_stamp() - begin < action)
		usleep(500);
}

long long	time_stamp(void)
{
	long long			time;
	struct timeval		currant_time;

	gettimeofday(&currant_time, NULL);
	time = ((currant_time.tv_sec * 1000) + (currant_time.tv_usec / 1000));
	return (time);
}

