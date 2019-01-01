/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:18:21 by exam              #+#    #+#             */
/*   Updated: 2018/12/27 15:44:43 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define EQ_B board[j][i] == 'B'
#define EQ_R board[j][i] == 'R'
#define EQ_Q board[j][i] == 'Q'
#define EQ_P board[j][i] == 'P'

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
		while (board[j][i])
			i++;
		if (i != size)
			return (1);
		i = 0;
		while (i < size)
			if (board[j][i++] == 'K')
				king++;
		j++;
	}
	if (king != 1)
		return (1);
	return (0);
}

int		check_cross(char **board, int i, int j, int size)
{
	int tmp_i;
	int tmp_j;

	tmp_i = i;
	tmp_j = j;
	while (++i < size && !(EQ_B || EQ_P))
		if (EQ_R || EQ_Q)
			return (1);
	i = tmp_i;
	while (--i >= 0 && !(EQ_B || EQ_P))
		if (EQ_R || EQ_Q)
			return (1);
	i = tmp_i;
	while (++j < size && !(EQ_B || EQ_P))
		if (EQ_R || EQ_Q)
			return (1);
	j = tmp_j;
	while (--j >= 0 && !(EQ_B || EQ_P))
		if (EQ_R || EQ_Q)
			return (1);
	return (0);
}

int		check_diagonal(char **board, int i, int j, int size)
{
	int tmp_i;
	int tmp_j;

	tmp_i = i;
	tmp_j = j;
	while (++j < size && ++i < size && !(EQ_R || (EQ_P && i != tmp_i + 1)))
		if (EQ_Q || EQ_B || (EQ_P && i == tmp_i + 1))
			return (1);
	j = tmp_j;
	i = tmp_i;
	while (++j < size && --i >= 0 && !(EQ_R || (EQ_P && i != tmp_i - 1)))
		if (EQ_Q || EQ_B || (EQ_P && i == tmp_i - 1))
			return (1);
	i = tmp_i;
	j = tmp_j;
	while (--j >= 0 && --i >= 0 && !(EQ_R || EQ_P))
		if (EQ_Q || EQ_B)
			return (1);
	i = tmp_i;
	j = tmp_j;
	while (--j >= 0 && ++i < size && !(EQ_R || EQ_P))
		if (EQ_Q || EQ_B)
			return (1);
	return (0);
}

int		check_mate(char **board, int size)
{
	int j;
	int i;

	j = 0;
	if (!check_board(board, size))
	{
		while (j < size)
		{
			i = 0;
			while (i < size)
			{
				if (board[j][i] == 'K')
					return (check_cross(board, i, j, size) || check_diagonal(board, i, j, size));
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
		check_mate(av + 1, ac - 1) ? write(1, "Success", 7) : write(1, "Fail", 4);
	write(1, "\n", 1);
	return (0);
}
