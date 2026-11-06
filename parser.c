/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:28:10 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/04 12:29:25 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int check_min_max(const char *str, int i, int sign, int *result)
{
    int num;
    int digit;
    int limit;

    num = 0;
    limit = -INT_MAX;
    if (sign == -1)
        limit = INT_MIN;
    while (str[i] >= '0' && str[i] <= '9')
    {
        digit = str[i] - '0';
        if (num < (limit + digit) / 10)
            return (0);
        num = num * 10 - digit;
        i++;
    }
    if (str[i] != '\0')
        return (0);
    if (sign == 1)
        num = -num;
    *result = num;
    return (1);
}

int ft_atoi(const char *str, int *result)
{
    int i;
    int sign;

    if (!str || !result)
        return (0);
    i = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (str[i] < '0' || str[i] > '9')
        return (0);
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

int get_args(int argc, char **argv, t_args *arr)
{
    int i;
    int result[7];
    char *scheduler;

    if (argc != 9)
        return (0);
    i = 1;
    while (i < 8)
    {
        if (!ft_atoi(argv[i] , &result[i - 1]))
            return (0);
        i++;
    }
    scheduler = get_scheduler(argv[8]);
    if (!scheduler)
        return (0);
    arr->number_of_coders = result[0];
	arr->time_to_burnout = result[1];
	arr->time_to_compile = result[2];
	arr->time_to_debug = result[3];
	arr->time_to_refactor = result[4];
	arr->number_of_compiles_required = result[5];
	arr->dongle_cooldown = result[6];
	arr->scheduler = scheduler;
	return (1);
}
