#include "codexion.h"

void	print_args(t_args arr)
{
	printf("\nARGS:\n");
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
	printf("\nCODERS\n");
	while (i < arr.number_of_coders)
	{
		printf("\nCoder ID: %i\n", coders[i].id);
		//printf("Thread result: %lu\n", coders[i].thread);
		printf("Left dongle ID: %i\n", coders[i].left_dongle->id);
		printf("Right dongle ID: %i\n", coders[i].right_dongle->id);
		printf("Last compiled at %i\n", coders[i].last_compiled_at);
		printf("Compiled %i time\n", coders[i].compiled);
		i++;
	}
}

void	print_dongles(t_args arr, t_dongle *dongles)
{
	int	i;

	i = 0;
	printf("\nDONGLES\n");
	while (i < arr.number_of_coders)
	{
		printf("Dongle ID: %i\n", dongles[i].id);
		printf("In Use: %d\n", dongles[i].in_use);
		printf("Mutex: %p\n", (void *)&dongles[i].mutex);
		i++;
	}
}

void	print_time(long start_time)
{
	printf("\nTIME\n");
	printf("Start Time: %ld\n", start_time);
}

void	print_all(t_args arr, t_coder *coders, t_dongle *dongles, long start_time)
{
	print_args(arr);
	print_dongles(arr, dongles);
	print_coders(arr, coders);
	print_time(start_time);
}
