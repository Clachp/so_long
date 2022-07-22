/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:08:19 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 15:57:26 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_char(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}	
	return (0);
}

static int	count_set(char const *s1, char const*set)
{
	int	i;

	i = 0;
	while (check_char(set, s1[i]))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*st;
	size_t	i;
	size_t	l;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = count_set(s1, set);
	l = ft_strlen(s1);
	if (l == i)
	{
		l = 0;
		i = 0;
	}
	while (check_char(set, s1[l - 1]))
		l--;
	str = malloc(sizeof(char) * (l - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (i < l)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (st = str);
}
/*
int	main(void)
{
	char *s = "|||///Salut/Ca|Va|/";
	char *set = "|/";
	//char *s = "   xxx   xxx";
	//char *set = " x";
	printf("%s\n", ft_strtrim(s, set));
	return (0);
}*/
