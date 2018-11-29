/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:18:21 by exam              #+#    #+#             */
/*   Updated: 2018/11/27 11:41:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int		check_board(char **board, int size)
{
	int j;
	int i;
	int king;

	j = 0;
	king = 0;
	while (j < size)
	{
		i = 0;
		if (ft_strlen(board[j]) != size)
			return (1);
		while (i < size)
			if (board[j][i++] == 'K')
				king++;
		j++;
	}
	if (king != 1)
		return (1);
	return (0);
}

int		check_mate(char **board, int size)
{
	int j;
	int i;
	int tmp_j;
	int tmp_i;

	j = 0;
	if (!check_board(board, size))
	{
		while (j < size)
		{
			i = 0;
			while (i < size)
			{
				if (board[j][i] == 'K')
				{
					tmp_i = i;
					while (++i < size)
					{
						if (EQ_R || EQ_Q)
							return (1);
						else if (EQ_B || EQ_P)
							break ;
					}
					i = tmp_i;
					while (--i >= 0)
					{
						if (EQ_R || EQ_Q)
							return (1);
						else if (EQ_B || EQ_P)
							break ;
					}
					i = tmp_i;
					tmp_j = j;
					while (++j < size)
					{
						if (EQ_R || EQ_Q)
							return (1);
						else if (EQ_B || EQ_P)
							break ;
					}
					j = tmp_j;
					while (--j >= 0)
					{
						if (EQ_R || EQ_Q)
							return (1);
						else if (EQ_B || EQ_P)
							break ;
					}
					j = tmp_j;
					while (++j < size && ++i < size)
					{
						if (EQ_Q || EQ_B || (EQ_P && i == tmp_i + 1))
							return (1);
						else if (EQ_R || EQ_P)
							break ;
					}
					j = tmp_j;
					i = tmp_i;
					while (++j < size && --i >= 0)
					{
						if (EQ_Q || EQ_B || (EQ_P && i == tmp_i - 1))
							return (1);
						else if (EQ_R || EQ_P)
							break ;
					}
					i = tmp_i;
					j = tmp_j;
					while (--j >= 0 && --i >= 0)
					{
						if (EQ_Q || EQ_B)
							return (1);
						else if (EQ_R || EQ_P)
							break ;
					}
					i = tmp_i;
					j = tmp_j;
					while (--j >= 0 && ++i < size)
					{
						if (EQ_Q || EQ_B)
							return (1);
						else if (EQ_R || EQ_P)
							break ;
					}
					i = tmp_i;
					j = tmp_j;
				}
				i++;
			}
			j++;
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		(check_mate(av + 1, ac - 1) ? ft_putstr("Success") : ft_putstr("Fail"));
	ft_putchar ('\n');	
	return (0);
}
