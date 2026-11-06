#include <sys/time.h>
#include <stdio.h>


void print_hello()
{
	int	i;

	i = 0;
	while (i++ < 100)
		printf("Hello\n");
}


int	main(void)
{
	struct timeval start, end;
	double	time_taken;

	gettimeofday(&start, NULL);

	print_hello();

	gettimeofday(&end, NULL);
	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
	printf("Time taken: %f\n", time_taken);
	return (0);
}
