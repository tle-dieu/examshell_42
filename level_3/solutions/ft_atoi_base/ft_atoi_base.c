/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:10:58 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/12 15:03:18 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_base(char c, int base)
{
	char *base_min;
	char *base_maj;

	base_min = "0123456789abcdef\0";
	base_maj = "0123456789ABCDEF\0";
	while (base--)
		if (base_maj[base] == c || base_min[base] == c)
			return (1);
	return (0);
}

int		value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (is_base(*str, str_base))
		result = result * str_base + value(*str++);
	return (result * sign);
}
