/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:04:57 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/02 15:54:19 by irdzhupy         ###   ########.fr       */
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

void	*routine()
{
	printf("hello from thread\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_args	arr;
	t_coder	*coders;
	int	i;
	int	j;

	if (get_args(argc, argv, &arr))
		return (error_exit("Invalid arguments\n"));
	coders = malloc(arr.number_of_coders * sizeof(t_coder));
	if (!coders)
		return (1);
	i = 0;
	while (arr.number_of_coders > i)
	{
		coders[i].id = i + 1;
		if (pthread_create(&coders[i].thread, NULL, &routine, &coders[i]) != 0)
		{
			free(coders);
		}
		// second param is the result of the thread
		pthread_join(coders[i].thread, NULL);
		i++;
	}

	print_args(arr);
	j = 0;
	while (j < arr.number_of_coders)
	{
		print_coder(arr, coders);
		j++;
	}
	return (0);
}
