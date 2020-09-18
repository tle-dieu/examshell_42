/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:44:23 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/11 21:05:55 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	while (*s)
		ft_putchar(*s++);
}

int		wdmatch(const char *str, const char *alpha)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!alpha[j])
			return (0);
		if (alpha[j] == str[i])
			i++;
		j++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		if (wdmatch(av[1], av[2]))
			ft_putstr(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
