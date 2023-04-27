/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:50:19 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/27 19:20:13 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosophers	philo;

	// philo = malloc(sizeof(t_philosophers));
	if (argc == 6 || argc == 5)
	{
		if (!check_arg(argc, argv) || !init_args(&philo, argc, argv))
		{
			printf("error\n");
			return (0);
		}
		printf("hello");
	}
	else
		printf("error\n");
}
