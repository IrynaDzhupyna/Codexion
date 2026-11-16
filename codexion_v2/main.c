/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:50:00 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/16 14:50:00 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	memset(&sim, 0, sizeof(t_sim));
	if (!get_args(argc, argv, &sim.arr))
		return (error_exit("Error: invalid arguments\n", &sim));
	if (!init_sim(&sim))
		return (error_exit("Error: initialization failed\n", &sim));
	if (!run_simulation(&sim))
		return (error_exit("Error: thread creation failed\n", &sim));
	cleanup(&sim);
	return (0);
}
