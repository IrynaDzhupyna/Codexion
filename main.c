/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:32:39 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/09 19:41:47 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_args	arr;
	t_dongle *dongles;
	t_coder	*coders;

	if (argc < 9)
		return (1);
	if (!get_args(argc, argv, &arr))
		return (1);
	print_args(arr);
	dongles = malloc(arr.number_of_coders * sizeof(t_dongle));
	if (!dongles)
		return (1);
	if (!init_dongles(arr, dongles))
		return (1);
	print_dongles(arr, dongles);
	coders = malloc(arr.number_of_coders * sizeof(t_coder));
	if (!coders)
		return (1);
	if (!init_coders(arr, dongles, coders))
		return (1);
	print_coders(arr, coders);
	return (0);
}
