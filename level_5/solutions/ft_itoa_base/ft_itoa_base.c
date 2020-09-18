#include <stdlib.h>

int		ft_count_nb(int nb, int base)
{
	unsigned int	abs;
	int				count;

	count = 0;
	if (nb < 0)
	{
		if (base == 10)
			count++;
		abs = -nb;
	}
	else
		abs = nb;
	while (abs)
	{
		abs /= base;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(int value, int base)
{
	int				i;
	char			*nbr;
	char			*base_str;
	unsigned int	abs;

	i = ft_count_nb(value, base);
	base_str = "0123456789ABCDEF\0";
	if (!(nbr = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nbr[i--] = '\0';
	if (value < 0)
	{
		abs = -value;
		if (base == 10)
			nbr[0] = '-';
	}
	else
		abs = value;
	while (abs)
	{
		nbr[i--] = base_str[abs % base];
		abs /= base;
	}
	return (nbr);
}
