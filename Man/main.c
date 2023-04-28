/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:50:19 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/28 19:19:32 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info	*args;
	// t_attribute *philosophers;

	args = malloc(sizeof(t_info));
	if (argc == 6 || argc == 5)
	{
		if (!check_arg(argv) || !init_args(args, argc, argv))
		{
			printf("error\n");
			free(args);
			return (0);
		}
		printf("hello");
	}
	else
		printf("error\n");

	//************************
	// philosophers // is the head of the list
	// 1 -- N-philo // index will pass to fl_sltnew as id of philo
	// send(args); // shared data or args
	//**************************
}
