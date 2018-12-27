/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:12:58 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/12/27 14:27:42 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char comp;

	comp = 128;
	while (comp >= 1)
	{
		if (comp & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		comp /= 2;
	}
}
