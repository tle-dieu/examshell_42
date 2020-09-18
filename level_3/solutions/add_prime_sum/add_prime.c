#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = nb % 10 + 48;
	write(1, &nb, 1);
}

#include <stdio.h>

int		ft_atoi(char const *str)
{
	int			sign;
	unsigned	result;

	result = 0;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - 48;
	return ((int)result * sign);
}

void	prime_sum(int nb)
{
	int prime;
	int div;
	int total;
	int is_prime;

	prime = 1;
	total = 0;
	while ((prime += 2) <= nb)
	{
		div = 2;
		is_prime = 1;
		while ((div <= prime / 2) && is_prime)
		{
			if (!(prime % div++))
				is_prime = 0;
		}
		if (is_prime)
			total += prime;
	}
	ft_putnbr(total + 2);
}

int		main(int ac, char **av)
{
	int		nb;

	ac != 2 || (nb = ft_atoi(av[1])) <= 1 ? write(1, "0", 1) : prime_sum(nb);
	write(1, "\n", 1);
	return (0);
}
