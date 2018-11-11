/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:58:56 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/11 15:17:10 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_last_word(const char *s)
{
	int i;

	i = 0;
	while (s[i + 1])
		i++;
	while (i && (s[i] == ' ' || s[i] == '\t'))
		i--;
	while (i - 1 && s[i - 1] != ' ' && s[i - 1] != '\t')
		i--;
	while (s[i] != ' ' && s[i] != '\t' && s[i])
		ft_putchar(s[i++]);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_last_word(av[1]);	
	ft_putchar('\n');
	return (0);
}
