/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:10:34 by exam              #+#    #+#             */
/*   Updated: 2018/11/13 11:10:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
	unsigned int abs;

	if (nb < 0)
	{
		abs = -nb;
		ft_putchar('-');
	}
	else
		abs = nb;
	if (abs > 9)
		ft_putnbr(abs / 10);
	ft_putchar(abs % 10 + 48);
}

int     main(int ac, char **av)
{
	(void)av;
	ft_putnbr(ac - 1);
	ft_putchar('\n');
	return (0);
}
