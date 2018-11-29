/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:01:05 by exam              #+#    #+#             */
/*   Updated: 2018/11/13 12:59:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int		cycle_detector(const t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 100000)
			return (1);
		list = list->next;
		i++;

	}
	return (0);
}
