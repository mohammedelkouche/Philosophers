/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:50:19 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/03 18:59:44 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info		*info;
	t_philos	*head;

	head = NULL;
	info = malloc(sizeof(t_info));
	if (argc == 6 || argc == 5)
	{
		if (!check_arg(argv) || !init_args(info, argc, argv))
		{
			printf("error\n");
			free(info);
			return (0);
		}
	head = create_list(head, info);
	init_thread(head, info);
	// while(head)
	// {
	// 	printf("%d\t", head->id);
	// 	head = head->next;
	// 	if(head->id == 1)
	// 		break;
	// }
	}
	else
		printf("error\n");
	return (0);
}
