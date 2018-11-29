/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:12:46 by exam              #+#    #+#             */
/*   Updated: 2018/11/13 11:46:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_size(const char *str)
{
	int words;

	words = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str)
			words++;
		while (*str != ' ' && *str != '\t' && *str != '\n' && *str)
			str++;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
	}
	return (words);
}

char	*ft_strsub(const char *str, int start, int len)
{
	char 	*new;
	int		i;

	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		words;
	int		j;
	int		i;
	int		occ;

	words = ft_count_size(str);
	if (!(tab = (char **)malloc(sizeof(char *) * words + 1)))
		return (NULL);
	j = 0;
	i = 0;
	while (j < words)
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		occ = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			i++;
		tab[j++] = ft_strsub(str, occ, i - occ);
	}
	tab[j] = NULL;
	return (tab);
}
