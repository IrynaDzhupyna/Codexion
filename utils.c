/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:21:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/13 12:57:56 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long	get_current_time(void)
{
	struct timespec current;

	clock_gettime(CLOCK_MONOTONIC, &current);
	return (current.tv_sec * 1000L + current.tv_nsec / 1000000L);
}

/*long	current_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (current.tv_sec * 1000L + current.tv_usec / 1000L);
}*/

long	get_elapsed_time(long start_time)
{
	long	current;

	current = get_current_time();
	return (current - start_time);
}
