//should we have a header here???
#ifndef CODEXION_H
#define CODEXION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>


#include <time.h>

typedef struct	s_args
{
	int	number_of_coders;
	int	time_to_burnout;
	int	time_to_compile;
	int	time_to_debug;
	int	time_to_refactor;
	int	number_of_compiles_required;
	int	dongle_cooldown;
	char	*scheduler;
}	t_args;

typedef struct	s_dongle
{
	int	id;
	bool	in_use;
	pthread_mutex_t	mutex;
}	t_dongle;

typedef struct s_coder
{
	int	id;
	int	left_dongle;
	int	right_dongle;
	int	last_compiled_at;
	int	compiled;
	pthread_t	thread;
}	t_coder;

typedef struct 	s_sim
{
	t_args	arr;
	t_coder	*coders;
	t_dongle	*dongles;

}	t_sim;

//parser.c
int	get_args(int argc, char **argv, t_args *arr);

//dongles.c
int	init_dongles(t_args arr, t_dongle *dongles);

//coders.c
int	init_coders(t_args arr, t_dongle *dongles, t_coder *coders);
int	create_threads(t_args arr, t_coder *coders);


//routine.c
void	*coder_routine(void *args);

//utils.c
long	get_current_time(void);
long	get_elapsed_time(long start_time);

//print.c
void	print_args(t_args arr);
void	print_dongles(t_args arr, t_dongle *dongles);
void	print_coders(t_args arr, t_coder *coders);
void	print_time(long start_time);
void	print_all(t_args arr, t_coder *coders, t_dongle *dongles, long start_time);

#endif
