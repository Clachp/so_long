/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:12:16 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 15:57:58 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int	main(void)
{
	printf("strdup : %s\n", strdup("string"));
	printf("ft_strdup : %s\n", ft_strdup("string"));
}*/
