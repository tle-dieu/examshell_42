/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:03:58 by exam              #+#    #+#             */
/*   Updated: 2018/12/27 00:56:35 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		brackets(char *s)
{
	int bracket;
	char *last;

	last = s;
	bracket = 0;
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
		{
			if (*s == '(')
				*last++ = ')';
			else if (*s == '{')
				*last++ = '}';
			else
				*last++ = ']';
			bracket++;
		}
		else if (*s == ')' || *s == '}' || *s == ']')
			if (!bracket-- || *--last != *s)
				return (1);
		s++;
	}
	return (bracket);
}

int		main(int ac, char **av)
{
	int i;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			if (brackets(av[i++]))
				write(1, "Error\n", 6);
			else
				write(1, "OK\n", 3);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
