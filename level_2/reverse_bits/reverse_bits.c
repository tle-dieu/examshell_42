/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:36:53 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/11 12:21:01 by tle-dieu         ###   ########.fr       */
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
