/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:27:25 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/16 13:54:26 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	compile(t_coder *coder)
{
	if (!coder)
		return (0);
	if (pthread_mutex_lock(&coder->left_dongle->mutex) != 0)
		return (0);
	if (pthread_mutex_lock(&coder->right_dongle->mutex) != 0)
		return (0);
	coder->left_dongle->in_use = true;
	coder->right_dongle->in_use = true;
	//printf("Left_dongle in_use: %i\n", coder->left_dongle->in_use);
	//printf("Right_dongle in_use: %i\n", coder->right_dongle->in_use);
	printf("Coder %i compiling\n", coder->id);
	usleep(200);
	if (pthread_mutex_unlock(&coder->left_dongle->mutex) != 0)
		return (0);
	if (pthread_mutex_unlock(&coder->right_dongle->mutex) != 0)
		return (0);
	coder->left_dongle->in_use = false;
	coder->right_dongle->in_use = false;
	//printf("Left_dongle in_use: %i\n", coder->left_dongle->in_use);
	//printf("Right_dongle in_use: %i\n", coder->right_dongle->in_use);
	return (1);
}

int	debug(t_coder *coder)
{
	printf("Coder %i debugging\n", coder->id);
	usleep(200);
	return (1);
}

int	refactor(t_coder *coder)
{
	printf("Coder %i refactoring\n", coder->id);
	usleep(100);
	return (1);
}

void	*coder_routine(void *args)
{
	t_coder	*coder;

	coder = (t_coder *)args;
	compile(coder);
	//this line does not work
	//coder->compiled++;
	debug(coder);
	refactor(coder);
	printf("\n");
	return (NULL);
}
