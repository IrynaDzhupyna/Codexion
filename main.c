/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:04:57 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/10/29 18:31:31 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	check_min_max(const char *str, int i, int sign, int *result)
{
	int	num;
	int	digit;
	int	limit;

	num = 0;
	limit = -INT_MAX;
	if (sign == -1)
		limit = INT_MIN;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if (num < (limit + digit) / 10)
			return (1);
		num = num * 10 - digit;
		i++;
	}
	if (str[i] != '\0')
		return (1);
	if (sign == 1)
		num = -num;
	*result = num;
	return (0);
}

int	ft_atoi(const char *str, int *result)
{
	int	i;
	int	sign;

	if (!str || !result)
		return (1);
	i = 0;
	sign = 1;
	while (str[i] == ' ' ||(str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (1);
	return (check_min_max(str, i, sign, result));
}

char	*get_scheduler(char *argv)
{
	if (!argv)
		return (NULL);
	if (strcmp(argv, "fifo") == 0)
		return ("fifo");
	if (strcmp(argv, "edf") == 0)
		return ("edf");
	return (NULL);
}

int	get_args(int argc, char **argv, t_args *arr)
{
	int	i;
	int	data[7];
	char	*scheduler;

	if (argc != 9)
		return (1);
	i = 1;
	while (i < 8)
	{
		if (ft_atoi(argv[i], &data[i - 1]))
			return (1);
		i++;
	}
	scheduler = get_scheduler(argv[8]);
	if (!scheduler)
		return (1);
	arr->number_of_coders = data[0];
	arr->time_to_burnout = data[1];
	arr->time_to_compile = data[2];
	arr->time_to_debug = data[3];
	arr->time_to_refactor = data[4];
	arr->number_of_compiles_required = data[5];
	arr->dongle_cooldown = data[6];
	arr->scheduler = scheduler;
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	arr;

	if (get_args(argc, argv, &arr))
	{
		printf("Invalid arguments\n");
		return (1);
	}
	printf("Number of coders: %d\n", arr.number_of_coders);
	printf("Time to burnout: %d\n", arr.time_to_burnout);
	printf("Time to compile: %d\n", arr.time_to_compile);
	printf("Time to debug: %d\n", arr.time_to_debug);
	printf("Time to refactor: %d\n", arr.time_to_refactor);
	printf("Compiles required: %d\n", arr.number_of_compiles_required);
	printf("Dongle cooldown: %d\n", arr.dongle_cooldown);
	printf("Scheduler: %s\n", arr.scheduler);
	return (0);
}
