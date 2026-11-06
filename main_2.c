/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:59:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/06 19:46:35 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	error_exit(char *s)
{
	fprintf(stderr, "%s", s);
	return (1);
}

int     free_all(t_dongle dongles, t_coder coders)
{
    int i;

    i = 0;
    while (i < arr.number_of_coders)
    {
        free(dongles[i]);
        i++;
    }
    i = 0;
    while (i < arr.number_of_coders)
    {
        free(coders[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_args  arr;
    t_dongle    *dongles;
    t_coder     *coders;

    if (!get_args(argc, argv, &arr))
        return (error_exit("Invalid arguments\n"));
    
    dongles = malloc(arr.number_of_coders * sizeof(t_dongle));
    if (!dongles)
        return (error_exit("Dongle allocation failed\n"));
    if (!init_dongles(arr, dongles))
        return (error_exit("Dongles init failed\n"))
    print_dongles(arr, dongles);
    
    coders = malloc(arr.number_of_coders * sizeof(t_coder));
    if (!coders)
        return (error_exit("Coder allocation failed\n");
    if (!init_coders(arr, coders, dongles))
        return (error_exit("Coders init failed\n"));
    print_coders(arr, coders);
    free_all(dongles, coders);
    return (0);
}
