#include <stdio.h>
#include <pthread.h>

int TIME_TO_COMPILE = 200;
int TIME_TO_DEBUG = 200;
int TIME_TO_REFACTOR = 200;

//int	error_exit(char *s)
//{
//	fprintf(stderr, "%s\n", s);
//	return (1);
//}

int	compile()
{
	printf("Compiling\n");
	return (1);
}

void	*routine(void *args)
{
	if ((int *)args < 0)
		return (0);
	if (!compile())
		return (0);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int	i;
	pthread_t	t1;

	if (pthread_create(&t1, NULL, &routine, &TIME_TO_COMPILE, &i) != 0)
		return (1);
	if (pthread_join(t1, NULL) != 0)
		return (2);
	return (0);
}
