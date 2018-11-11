/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:10:40 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/11 12:22:10 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	ft_alpha_mirror(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z') 
			s[i] = 'z' - s[i] + 'a';
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = 'Z' - s[i] + 'A';
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_alpha_mirror(av[1]);
		ft_putstr(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
