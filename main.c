/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:04:57 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/02 17:32:38 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

//void	print_args(t_args arr)
//{
//	printf("Number of coders: %d\n", arr.number_of_coders);
//	printf("Time to burnout: %d\n", arr.time_to_burnout);
//	printf("Time to compile: %d\n", arr.time_to_compile);
//	printf("Time to debug: %d\n", arr.time_to_debug);
//	printf("Time to refactor: %d\n", arr.time_to_refactor);
//	printf("Compiles required: %d\n", arr.number_of_compiles_required);
//	printf("Dongle cooldown: %d\n", arr.dongle_cooldown);
//	printf("Scheduler: %s\n", arr.scheduler);	
//}

int	error_exit(char *s)
{
	fprintf(stderr, "%s", s);
	return (1);
}

void	*routine(void *args)
{
	int	i;

	i = *(int *)args;
	printf("hello from thread %i\n", i);
	return (NULL);
}

int	init_coders(t_args arr, t_coder coders)
{
	int	i;

	coders = malloc(arr.number_of_coders * sizeof(t_coder));
	if (!coders)
		return (1);
	i = 0;
	while (i < arr.number_of_coders)
	{
		coders[i].id = i + 1;
		if (pthread_create(coders[i].thread, NULL, &routine, coder[i].id) != 0)
		{
			free(coders);
			return (1);
		}
		pthread_join(coders[i].thread, NULL);
		i++;
	}
	return (0);
}	
	
int	main(int argc, char **argv)
{
	t_args	arr;
	t_coder	*coders;
	//int	i;

	if (get_args(argc, argv, &arr))
		return (error_exit("Invalid arguments\n"));
//	coders = malloc(arr.number_of_coders * sizeof(t_coder));
//	if (!coders)
		return (1);
	//i = 0;
//	while (arr.number_of_coders > i)
//	{
//		coders[i].id = i + 1;
//		if (pthread_create(&coders[i].thread, NULL, &routine, &coders[i].id) != 0)
//		{
//			free(coders);
//		}
		// second param is the result of the thread
		//print_coder(&coders[i].id);
//		pthread_join(coders[i].thread, NULL);
//		i++;
//	}

	print_args(arr);
	print_coder(arr, coders);
	return (0);
}
