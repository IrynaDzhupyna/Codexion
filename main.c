/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:23:24 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/06 11:30:08 by irdzhupy         ###   ########.fr       */
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
	t_coder		*coders;
	t_dongle	*dongles;

	if (!get_args(argc, argv, &arr))
		return (error_exit("Invalid arguments\n"));
	coders = malloc(arr.number_of_coders * sizeof(t_coder));
	// should we free if allocation failed
	if (!coders)
		return (error_exit("Allocation for coders failed\n"));
	//print_args(arr);
	if (!init_coders(arr, coders))
		return (error_exit("Init of dongles failed\n"));
	//print_coders(arr, coders);
	dongles = malloc(arr.number_of_coders * sizeof(t_dongle));
	if (!dongles)
		return (error_exit("Dongles allocation failed\n"));
	if (!init_dongles(arr, dongles))
		return (error_exit("Init of dongles failed\n"));
	print_dongles(arr, dongles);
	
	return (0);
}

