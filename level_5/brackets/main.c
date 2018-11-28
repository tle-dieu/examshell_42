#include "brackets.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		ft_putchar('\n');
	while (--ac)
		brackets(av[ac]);
	return (0);
}
