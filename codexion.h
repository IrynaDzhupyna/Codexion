#ifndef CODEXION_H
#define CODEXION_H

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

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

typedef struct s_coder
{
    int             id;
    pthread_t       thread;
    long            last_compile_start;
    int             compile_count;
    int             left_dongle;
    int             right_dongle;
    //struct s_sim    *simulation;
}   t_coder;

typedef struct s_dongle
{
    int			id;
    int			in_use;
    long		available_at;
    pthread_mutex_t 	mutex;
}   t_dongle;

int	get_args(int argc, char **argv, t_args *arr);

int	init_dongles(t_args arr, t_dongle *dongles);
int	destroy_dongles(t_args arr, t_dongle *dongles);

int     init_coders(t_args arr, t_coder *coders, t_dongle *dongles);

void	print_args(t_args arr);
void	print_coders(t_args arr, t_coder *coders);
void    print_dongles(t_args arr, t_dongle *dongles);

#endif
