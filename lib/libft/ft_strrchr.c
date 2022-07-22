/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:40:51 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 11:57:55 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (c == 0)
		return ((char *)s + l);
	if (c > 127 && c < 257)
		return (NULL);
	c %= 256;
	while (l--)
	{
		if (s[l] == c)
			return ((char *)s + l);
	}
	return (NULL);
}
/*
int main()
{
	char s[] = "tripouille";
	char s1[] = "ltripouiel";
	printf("ft_strrchr : %s\n", ft_strrchr(s, 't' + 100));
	printf("strrchr : %s\n", strchr(s, 't' + 100));
}*/