/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:42:51 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/24 10:04:24 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	while (i < n && *s)
	{
		*(d + i) = *(s + i);
		i++;
	}
	while (i < n)
		*(d + i++) = '\0';
	return (dest);
}
/*
int	main (void)
{
	char dest[] = "Chat   ";
	char *src = NULL; 
	char *ft_result = ft_memcpy(dest, src, 0);
	char *result = memcpy(dest, src, 0);
	printf("ft_memcpy : %s\n", ft_result);
	printf("memcpy : %s\n", result);
	return (0);
}*/
