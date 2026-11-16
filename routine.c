/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:27:25 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/16 11:39:54 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	compile(t_coder *coder)
{
	if (!coder)
		return (0);
	if (pthread_mutex_lock(coder->left_dongle->mutex) != 0)
		return (0);
	if (pthread_mutex_lock(coder->right_dongle) != 0)
		return (0);
	usleep(20);
	if (pthread_mutex_unlock(coder->left_dongle) != 0)
		return (0);
	if (pthread_mutex_unlock(coder->right_dongle) != 0)
		return (0);
	return (1);
}

void	*coder_routine(void *args)
{
	t_coder	*coder;

	coder = (t_coder *)args;i
	compile(coder);
	usleep(10);
	usleep(5);

	// while i < nb_compiled or !coder_burnedout()
	// 	compile() - lock_dongle, take dongle, usleep(), unlock_dongle
	// 	debug() - usleep()
	// 	refactor() - usleep()
	return (NULL);
}
