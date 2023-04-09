/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:51:34 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/04/08 12:33:51 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// void*	routine()
// {
// 	printf("test frome threads\n");
// 	sleep(3);
// 	printf("Ending threads\n");
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	pthread_t	t1;
// 	pthread_t	t2;

// 	pthread_create(&t1, NULL, &routine, NULL);
// 	pthread_create(&t2, NULL, &routine, NULL);
// 	pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
// 	return (0);
// }

// int main(int argc, char* argv[]) {
//     pthread_t p1, p2;
//     if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
//         return 1;
//     }
//     if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
//         return 2;
//     }
//     if (pthread_join(p1, NULL) != 0) {
//         return 3;
//     }
//     if (pthread_join(p2, NULL) != 0) {
//         return 4;
//     }
//     return 0;
// }

/////////////////////////////////////////////////////

// int 	g_x = 2;
// pthread_mutex_t mutex;
// g_x = 2;

int mails = 0;
pthread_mutex_t mutex;

void*	routine() {
    for (int i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
        // read mails
        // increment
        // write mails
    }
	return(0);
}

//////////////////////////////////////////

// void*	routine()
// {
// 	g_x += 5;
// 	sleep(2);
// 	printf("Value of g_x: %d\n", g_x);
// 	return (0);
// }

// void*	routine2()
// {
// 	// g_x += 5;
// 	sleep(2);
// 	printf("Value of g_x: %d\n", g_x);
// 	return (0);
// }

int	main(int argc, char** argv)
{
	pthread_t	th[2];
	pthread_t	t1;
	pthread_t	t2;
	int			i;

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 2)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (pthread_join(th[i], NULL))
			return (2);
		i++;
	}
	pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
	// pthread_mutex_destroy(&mutex);
	// if (pthread_create(&t1, NULL, &routine, NULL))
	// 	return (1);
	// if (pthread_create(&t1, NULL, &routine, NULL))
	// 	return (2);
	// if (pthread_join(t1, NULL))
	// 	return (4);
	// if (pthread_join(t2, NULL))
	// 	return (5);
	//////////////////////////////////////////
	// if (pthread_create(&t2, NULL, &routine2, NULL))
	// 	return (3);
	return (0);
}
