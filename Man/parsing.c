/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:54:16 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/27 10:23:04 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	(void) argc;
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '+')
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
		}
	}
	return (1);
}
