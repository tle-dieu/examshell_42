
#include <stdio.h>
#include <stdlib.h>

int		get_pgcd(int nb1, int nb2)
{
	int pgcd;

	pgcd = nb1 > nb2 ? nb2 : nb1;
	while (nb1 % pgcd || nb2 % pgcd)
		pgcd--;
	return (pgcd);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%d", get_pgcd(atoi(av[1]), atoi(av[2])));
	printf("\n");
	return (0);
}
