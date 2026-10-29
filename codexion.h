#ifndef CODEXION_H
#define CODEXION_H

#include <stdio.h>
#include <limits.h>
#include <string.h>

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

typedef enum	e_scheduler
{
	FIFO,
	EDF
}	t_sched;

int	get_args(int argc, char **argv, t_args *arr);

#endif
