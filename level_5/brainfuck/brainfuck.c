#include <unistd.h>
#include <stdlib.h>

unsigned char	*ft_init_tab(size_t size)
{
	unsigned char *new;

	if (!(new = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	while (size)
		((unsigned char *)new)[--size] = 0;
	return (new);
}

char			*ft_begin_loop(char *srcode, unsigned char *byte)
{
	int count;


	if (!*byte)
	{
		count = 1;
		while (count)
		{
			srcode++;
			if (*srcode == ']')
				count--;
			else 
				if (*srcode == '[')
				count++;
		}
	}
	return (srcode);
}

char			*ft_end_loop(char *srcode, unsigned char *byte)
{
	int count;

	if (*byte)
	{
		count = 1;
		while (count)
		{
			srcode--;
			if (*srcode == ']')
				count++;
			else if (*srcode == '[')
				count--;
		}
	}
	return (srcode);
}

void			ft_brainfuck(char *srcode)
{
	unsigned char	*byte;

	byte = ft_init_tab(2048);
	while (*srcode)
	{
		if (*srcode == '.')
			write(1, byte, 1);
		else if (*srcode == '>')
			byte++;
		else if (*srcode == '<')
			byte--;
		else if (*srcode == '+')
			++*byte;
		else if (*srcode == '-')
			--*byte;
		else if (*srcode == '[')
			srcode = ft_begin_loop(srcode, byte);
		else if (*srcode == ']')
			srcode = ft_end_loop(srcode, byte);
		srcode++;
	}
}

int		main(int ac, char **av) 
{
	if (ac == 2)
		ft_brainfuck(av[1]);
	return (0);
}
