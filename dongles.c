#include "codexion.h"

int	destroy_dongles(t_args arr, t_dongle *dongles)
{
	int	i;

	i = 0;
	while (i < arr.number_of_coders)
	{
		if (pthread_mutex_destroy(&dongles[i].mutex) != 0)
			return (0);
		i++;
	}
	return (1);
}

int     init_dongles(t_args arr, t_dongle *dongles)
{
    int     i;

    i = 0;
    while (i < arr.number_of_coders)
    {
        dongles[i].id = i + 1;
        dongles[i].in_use = 0;
        dongles[i].available_at = 0;
	if (pthread_mutex_init(&dongles[i].mutex, NULL) != 0)
		return (0);
        i++;
    }
    return (1);
}
