/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:33:33 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/07 16:58:08 by tle-dieu         ###   ########.fr       */
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

void	search_and_replace(char *s, char search, char replace)
{
	while (*s)
	{
		if (*s == search)
			*s = replace;
		s++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!av[2][1] && !av[3][1])
		{
			search_and_replace(av[1], av[2][0], av[3][0]);
			ft_putstr(av[1]);
		}
	}
	ft_putchar('\n');
	return (0);
}
