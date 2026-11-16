#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*typedef	struct s_var
{
	int	n;
}	t_var;*/
int N = 5;

void	*routine_1()
{
	N = N + 5;
	return (0);
}

void	*routine_2()
{
	N = N + 3;
	return (0);
}

int	main()
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &routine_1, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine_2, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	printf("Num is now: %i\n", N);
	return (0);
}


