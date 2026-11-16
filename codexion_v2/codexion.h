/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:50:00 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/11/16 14:50:00 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <time.h>

typedef struct s_sim	t_sim;

typedef struct s_args
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;
}	t_args;

typedef struct s_dongle
{
	int				id;
	bool			in_use;
	pthread_mutex_t	mutex;
}	t_dongle;

typedef struct s_coder
{
	int			id;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	long		last_compiled_at;
	int			compiled;
	pthread_t	thread;
	t_sim		*sim;
}	t_coder;

struct s_sim
{
	t_args			arr;
	t_coder			*coders;
	t_dongle		*dongles;
	long			start_time;
	bool			stop;
	bool			mutexes_ready;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
};

/* parser.c */
int		get_args(int argc, char **argv, t_args *arr);

/* dongles.c */
int		init_dongles(t_args arr, t_dongle *dongles);

/* coders.c */
int		init_coders(t_args arr, t_dongle *dongles, t_coder *coders);

/* simulation.c */
int		init_sim(t_sim *sim);
int		run_simulation(t_sim *sim);
void	cleanup(t_sim *sim);
int		error_exit(char *msg, t_sim *sim);

/* routine.c */
void	*coder_routine(void *args);

/* utils.c */
long	get_current_time(void);
long	get_elapsed_time(long start_time);

#endif
