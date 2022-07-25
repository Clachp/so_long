/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:03:48 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 12:02:36 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while ((s1 != NULL || s2 != NULL) && i < n)
	{
		if (*(st1 + i) != *(st2 + i))
			return (*(st1 + i) - *(st2 + i));
		i++;
	}
	return (0);
}
/*
int main (void)
{
	const char s1[] = "abcdefgh";
	const char s2[] = "abcdwxyz";
	printf("memcmp : %d\n", memcmp(s1, s2, 7));
	printf("ft_memcmp : %d\n", ft_memcmp(s1, s2, 7));
}*/
