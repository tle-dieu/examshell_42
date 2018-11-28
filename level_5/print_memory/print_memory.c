#include <unistd.h>

void	print_ascii(int n)
{
	if (n > 31 && n < 127)
		write(1, &n, 1);
	else
		write(1, ".", 1);
}


void	print_hex(int n)
{
	char base[] = "0123456789abcdef";

	if (n > 15)
	{
		write(1, &base[(n / 16) % 16], 1);
		write(1, &base[n % 16], 1);
	}
	else if (n < 16)
	{
		write(1, "0", 1);
		write(1, &base[n % 16], 1);
	}
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*tab;
	size_t			i;
	size_t			j;

	tab = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16)
		{
			if (i + j < size)
				print_hex(tab[i + j]);
			else
				write(1, "  ", 2);
			if (++j && !(j % 2))
				write(1, "  ", 2);
		}
		while (j-- && i < size)
			print_ascii(tab[i++]);
		write(1, "\n", 1);
	}
}

int		main(void)
{
	int		tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
