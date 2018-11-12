/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:15:35 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/11 21:09:45 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		verif_char(const char *s, char c, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (verif_char(s1, s1[i],i))
			ft_putchar(s1[i]);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s2[i] != s1[j])
		{
			if (!s1[j])
			{
				if (verif_char(s2, s2[i], i))
				{
					ft_putchar(s2[i]);
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);		
	ft_putchar('\n');
}
