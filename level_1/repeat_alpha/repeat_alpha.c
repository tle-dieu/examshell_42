/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:45:23 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/07 16:00:22 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	repeat_alpha(const char *s)
{
	int i;

	while (*s)
	{
		if (*s >= 'a' && *s < 'z') 
			i = *s - 96;
		else if (*s >= 'A' && *s <= 'Z')
			i = *s - 64;
		else
			i = 1;
		while (i-- > 0)
			ft_putchar(*s);
		s++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	ft_putchar('\n');
	return (0);

}
