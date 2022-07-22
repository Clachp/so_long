/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:34:09 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 15:45:54 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_tab(char **tab, int i)
{
	while (--i)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	w;
	int	i;

	i = 0;
	w = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (w);
}

static int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] && s[i] != c)
	{	
		size++;
		i++;
	}
	return (size);
}

static void	cpy(char *dest, const char *s, int *i, int size)
{
	int	j;

	j = 0;
	while (s[*i] && j < size)
	{
		dest[j] = s[*i];
		(*i)++;
		j++;
	}
	dest[j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		w;
	char	**tab;

	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	tab[count_words(s, c)] = NULL;
	i = 0;
	w = 0;
	while (s && s[i])
	{
		if (s[i] && s[i] != c)
		{
			tab[w] = malloc((size_word(s, c, i) + 1) * sizeof(char));
			if (!tab[w])
				return (free_tab(tab, w));
			cpy(tab[w++], s, &i, size_word(s, c, i));
			i--;
		}
		i++;
	}
	return (tab);
}
/*
int	main(void)
{

	char	*s = "chinimala";
//	char 	*dest = "";
	char	c = ' ';
	char	**tab = ft_split(s, c);
//	printf("count_words : %d\n", count_words(s, c));
//	printf("size first word : %d\n", size_word(s, c, 4));
//	printf("mem and copy : %s\n", mem_and_cpy(dest, s + 4, size_word(s, c, 4)));
//	printf("size first word : %d\n", size_word(s, c, 0));

	int		i = 0;
	while (tab[i])
	{
		printf("tab[%d] : %s\n", i, tab[i]);
		i++;
	}
	//printf("tab[2] : %s\n", tab[2]);
	return (0);
}
*/
