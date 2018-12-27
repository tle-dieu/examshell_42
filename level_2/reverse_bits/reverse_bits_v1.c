/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits_v1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:07:20 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/12/27 15:07:21 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char comp;
	unsigned char rev;

	comp = 1;
	rev = 0;
	while (comp)
	{
		if (comp & octet)
			rev += 128 / comp;
		comp *= 2;
	}
	return (rev);
}
