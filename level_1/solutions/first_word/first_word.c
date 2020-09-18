/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:47:58 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/07 13:57:29 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_first_word(const char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	while ((*s != ' ' && *s != '\t') && *s)
		ft_putchar(*s++);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_first_word(av[1]);
	ft_putchar('\n');
	return (0);
}
