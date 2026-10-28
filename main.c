#include "codexion.h"

int	error_exit(char *s)
{
	write(1, s, ft_strlen(s));
	return 1;
}

static char	**get_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 9)
		return NULL
	if 
	return argv;
}

int	main(int argc, char **argv)
{
	t_args	*args;

	arr = get_args(argc, argv);
	if (!arr)
		return (error_exit("Error\n"));
	else
		return write(1, "ok", 2);
}
