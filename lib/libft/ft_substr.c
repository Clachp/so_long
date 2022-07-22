/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:52:55 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 12:27:34 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*save;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{	
		str = malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	if (ft_strlen(s) < (start + len))
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	save = str;
	while (len--)
		*str++ = s[start++];
	*str = '\0';
	return (save);
}
/*
int	main(void)
{
	printf("ft_substr : %s\n", ft_substr("Hello Claire!", 6, 8));
}*/
