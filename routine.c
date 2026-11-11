/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:27:25 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/11 20:50:45 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	compile(t_args arr)
{
	if (arr.time_to_compile < 0)
		return (0);
	sleep(arr.time_to_compile);
	return (1);
}

int	debug(t_args arr)
{
	if (arr.time_to_debug < 0)
		return (0);
	sleep(arr.time_to_debug);
	return (1);
}

int	refactor(t_args arr)
{
	if (arr.time_to_refactor < 0)
		return (0);
	sleep(arr.time_to_refactor);
	return (1);
}

void	*coder_routine(void *args)
{
	t_coder	*coder;

	coder = (t_coder *)args;

	while (simulation.is_finished)
	{
		take_dongle();

	// mutex_lock for two
	// so the in_use stays the same
	if (!compile())
	       return (0);
	//mutex_unlock for two
	if (!(debug() || refactor()))
		return (0);
	return (1);
}
