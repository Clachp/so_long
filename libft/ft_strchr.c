/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:40:51 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 15:55:44 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	c %= 256;
	str = (char *)s;
	if (c == 0)
		return (str + ft_strlen(s));
	while (s != NULL && str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("ft_strchr : %s\n strchr : %s\n", ft_strchr("", '\0'), strchr("", '\0'));
}*/
