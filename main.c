/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:32:39 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/16 11:47:26 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	error_exit(char *s)
{
	fprintf(stderr, "%s", s);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args		arr;
	t_dongle	*dongles;
	t_coder		*coders;
	long		start_time;

	if (!get_args(argc, argv, &arr))
		return (error_exit("Problem with parsering args"));
	//print_args(arr);
	dongles = malloc(arr.number_of_coders * sizeof(t_dongle));
	if (!dongles)
		return (error_exit("Dongles allocation failed\n"));
	if (!init_dongles(arr, dongles))
		return (error_exit("Dongle init failed\n"));
	//print_dongles(arr, dongles);
	coders = malloc(arr.number_of_coders * sizeof(t_coder));
	if (!coders)
		return (error_exit("Coders allocation failed\n"));
	if (!init_coders(arr, dongles, coders))
		return (error_exit("Coders init failed\n"));
	//print_coders(arr, coders);
	start_time = get_current_time();
	//printf("\nStart time: %ld\n", start_time);
	print_all(arr, coders, dongles, start_time);
	/*if (!create_threads(arr, coders))
		return (error_exit("Thread creation failed\n"));*/
	free(coders);
	free(dongles);
	return (0);
}
