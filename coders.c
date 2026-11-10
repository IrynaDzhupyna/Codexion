/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:34:42 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/10 11:15:36 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_coders(t_args arr, t_dongle *dongles, t_coder *coders)
{
	int	i;
	int	last_dongle;

	if (!dongles || !coders || arr.number_of_coders <= 0)
		return (0);
	i = 0;
	last_dongle = arr.number_of_coders - 1;
	while (i < arr.number_of_coders)
	{
		coders[i].id = i + 1;
		coders[i].left_dongle = dongles[i].id;
		if (coders[i].id == 1)
			coders[i].right_dongle = dongles[last_dongle].id;

		//for now it is not '0' as intended
		if (coders[i].id == last_dongle)
			coders[i].right_dongle = dongles[0].id;
		else
			coders[i].right_dongle = dongles[i + 1].id;
		i++;
	}
	return (1);
}
