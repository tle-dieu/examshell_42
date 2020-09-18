/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:18:39 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/11 21:10:08 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar (char c)
{
	write(1, &c, 1);
}

int		verif_char(const char *s, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (s[i] == s[index])
			return (0);
		i++;
	}
	return (1);
}

void	inter(char const *s1, char const *s2)
{
	int i;
	int j;

	j = 0;
	while (s1[j])
	{
		if (verif_char(s1, j))
		{
			i = 0;
			while (s2[i])
			{
				if (s1[j] == s2[i])
				{
						ft_putchar(s1[j]);
						break ;
				}
				i++;
			}
		}
		j++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
