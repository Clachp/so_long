/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:10:36 by cchapon           #+#    #+#             */
/*   Updated: 2022/06/13 16:56:53 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s))
	{
		*(str + i) = *(s + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	if (str == NULL)
		return (0);
	while (str[l])
		l++;
	return (l);
}

int	to_end(char *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}
