/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_coders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 20:11:36 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/06 21:24:21 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*routine(void *args)
{
	pthread_mutex_lock(&mutex);
	code();
	debug();
	refactor();
	pthread_mutex_unlock();
	return (NULL);
}
int	init_coders(t_args arr, t_coder *coders, t_dongle *dongles)
{
	int	i;

	if (!arr || !*coders || !*dongles)
		return (0);
	i = 0;
	while (i < arr.number_of_coders)
	{
		coders[i].id = i + 1;
		coders[i].last_compile_start = 0;
		coders[i].compile_count = 0;
		coders[i].left_dongle = &dongle[i];
		if (coders[i].id == 1)
			coders[i].right_dongle = &dongle[arr.number_of_coders];
		else
			coders[i].right_dongle = &dongle[i - 1];
		if (pthread_create(&coder[i].thread, NULL, &routine, &coder.id) != 0)
			return (0);
		i++;
	}

	i = 0;
	while (i < arr.number_of_coders)
	{
		if (pthread_join(coders[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	return (1)
}
