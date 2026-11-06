/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:39:12 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/06 20:11:56 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	code()
{
	printf("Coding in progress\n");
	return (1);
}

int	debug()
{
	printf("Debugging in progress\n");
	return (1);
}

int	refactor()
{
	printf("Refactoring in progress\n");
	return (1);
}

void    *routine(void *args)
{
    int     i;

    i = *(int *)args;
    printf("\nHello from thread %i\n", i);
    if (code() && debug() && refactor())
	    return (NULL);
    return (NULL);
}

int	get_dongles(t_args arr, t_coder *coders, t_dongle *dongles)
{
	int	i;

	i = 0;
	while (i < arr.number_of_coders)
	{
		if (coders[i].id == 1)
		{
			coders[i].left_dongle = &dongles[arr.number_of_coders - 1];
			coders[i].right_dongle = &dongles[i];
		}
		else
		{
			coders[i].left_dongle = &dongles[i];
			coders[i].right_dongle = &dongles[i - 1];
		}
		i++;
	}
	return (1);
}

int init_coder(t_args arr, t_coder *coder, t_dongle *dongles, int i)
{
    coder->id = i + 1;
    coder->last_compile_start = 0;
    coder->compile_count = 0;
    get_dongles(arr, coder, dongles);
    if (pthread_create(&coder->thread, NULL, &routine, &coder->id) != 0)
	    return (0);
    //dongles
    ////simulation
    return (1);
}

int init_coders(t_args arr, t_coder *coders, t_dongle *dongles)
{
    int     i;

    i = 0;
    while (i < arr.number_of_coders)
    {
        if (!init_coder(arr, &coders[i], dongles, i))
        {
            while (--i >= 0)
                pthread_join(coders[i].thread, NULL);
            return (0);
        }
        i++;
    }
    i = 0;
    while (i < arr.number_of_coders)
    {
        pthread_join(coders[i].thread, NULL);
        i++;
    }
    return (1);
}
