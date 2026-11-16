/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:50:00 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/16 14:50:00 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	init_shared_mutexes(t_sim *sim)
{
	if (pthread_mutex_init(&sim->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&sim->state_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&sim->print_mutex);
		return (0);
	}
	sim->mutexes_ready = true;
	return (1);
}

int	init_sim(t_sim *sim)
{
	int	i;

	sim->dongles = malloc(sizeof(t_dongle) * sim->arr.number_of_coders);
	if (!sim->dongles)
		return (0);
	if (!init_dongles(sim->arr, sim->dongles))
	{
		free(sim->dongles);
		sim->dongles = NULL;
		return (0);
	}
	sim->coders = malloc(sizeof(t_coder) * sim->arr.number_of_coders);
	if (!sim->coders)
		return (0);
	if (!init_coders(sim->arr, sim->dongles, sim->coders))
		return (0);
	i = 0;
	while (i < sim->arr.number_of_coders)
		sim->coders[i++].sim = sim;
	return (init_shared_mutexes(sim));
}

int	run_simulation(t_sim *sim)
{
	int		created;
	t_coder	*coder;

	sim->start_time = get_current_time();
	created = 0;
	while (created < sim->arr.number_of_coders)
	{
		coder = &sim->coders[created];
		if (pthread_create(&coder->thread, NULL, &coder_routine, coder) != 0)
			break ;
		created++;
	}
	if (created < sim->arr.number_of_coders)
	{
		pthread_mutex_lock(&sim->state_mutex);
		sim->stop = true;
		pthread_mutex_unlock(&sim->state_mutex);
	}
	while (created-- > 0)
		pthread_join(sim->coders[created].thread, NULL);
	return (!sim->stop);
}

void	cleanup(t_sim *sim)
{
	int	i;

	if (sim->dongles)
	{
		i = 0;
		while (i < sim->arr.number_of_coders)
			pthread_mutex_destroy(&sim->dongles[i++].mutex);
	}
	if (sim->mutexes_ready)
	{
		pthread_mutex_destroy(&sim->print_mutex);
		pthread_mutex_destroy(&sim->state_mutex);
	}
	free(sim->dongles);
	free(sim->coders);
	sim->dongles = NULL;
	sim->coders = NULL;
}

int	error_exit(char *msg, t_sim *sim)
{
	fprintf(stderr, "%s", msg);
	cleanup(sim);
	return (1);
}
