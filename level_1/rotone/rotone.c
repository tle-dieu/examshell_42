/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:21:21 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/07 16:33:15 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *s)
{
	while (*s)
	{
		if (*s == 'z' || *s == 'Z')
			ft_putchar(*s++ - 25);
		else if ((*s >= 'a' && *s <= 'y') || (*s >= 'A' && *s <= 'Y'))
			ft_putchar(*s++ + 1);
		else
			ft_putchar(*s++);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	ft_putchar('\n');
	return (0);
}
