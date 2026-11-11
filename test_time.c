#include <sys/time.h>
#include <stdio.h>

int	main()
{
	struct timeval	start;
	struct timeval	end;
	int	end;

	start = gettimeofday();
	printf("Started: %d\n", start);
	return (0);
}
