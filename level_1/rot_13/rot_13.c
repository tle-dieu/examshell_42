/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:05:44 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/07 16:30:08 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rot_13(const char *s)
{
	while (*s)
	{
		if ((*s >= 'a' && *s < 'n') || (*s >= 'A' && *s < 'N'))
			ft_putchar(*s++ + 13);
		else if ((*s >= 'n' && *s <= 'z') || (*s >= 'N' && *s <= 'Z'))
			ft_putchar(*s++ - 13);
		else
			ft_putchar(*s++);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rot_13(av[1]);
	ft_putchar('\n');
	return (0);
}
