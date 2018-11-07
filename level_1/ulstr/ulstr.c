/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:58:26 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/07 17:07:08 by tle-dieu         ###   ########.fr       */
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

void	ulstr(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32; 
		else if (*s >= 'A' && *s <= 'Z')
			*s += 32;
		s++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ulstr(av[1]);
		ft_putstr(av[1]);	
	}
	ft_putchar('\n');
	return (0);
}
