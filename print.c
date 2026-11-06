#include "codexion.h"

void	print_args(t_args arr)
{
	printf("Number of coders: %d\n", arr.number_of_coders);
	printf("Time to burnout: %d\n", arr.time_to_burnout);
	printf("Time to compile: %d\n", arr.time_to_compile);
	printf("Time to debug: %d\n", arr.time_to_debug);
	printf("Time to refactor: %d\n", arr.time_to_refactor);
	printf("Compiles required: %d\n", arr.number_of_compiles_required);
	printf("Dongle cooldown: %d\n", arr.dongle_cooldown);
	printf("Scheduler: %s\n", arr.scheduler);
}

void	print_coders(t_args arr, t_coder *coders)
{
	int	i;

	i = 0;
	while (i < arr.number_of_coders)
	{
		printf("Coder ID: %i\n", coders[i].id);
		printf("Thread result: %lu\n", coders[i].thread);
		printf("Last_compile_start: %lu\n", coders[i].last_compile_start);
		i++;
	}
}

void	print_dongles(t_args arr, t_dongle *dongles)
{
	int	i;

	i = 0;
	while (i < arr.number_of_coders)
	{
		printf("Dongle ID: %i\n", dongles[i].id);
		i++;
	}
}
