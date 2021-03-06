/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_print_bits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:27:11 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/12/27 14:32:27 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;

	i = 8;
	while (i--)
		write(1, (octet & 1 << i ? "1" : "0"), 1);
}
