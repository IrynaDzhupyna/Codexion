/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:34:01 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/11 11:54:56 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_dongles(t_args arr, t_dongle *dongles)
{
	int	i;

	if (!dongles)
		return (0);
	i = 0;
	while (i < arr.number_of_coders)
	{
		dongles[i].id = i + 1;
		dongles[i].in_use = false;
		if (pthread_mutex_init(&dongles[i].mutex, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
