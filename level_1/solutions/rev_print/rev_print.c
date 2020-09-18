/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:00:47 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/07 16:05:18 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rev_print(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
		ft_putchar(s[--i]);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	ft_putchar('\n');
	return (0);
}
