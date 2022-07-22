/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:47:01 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 12:01:38 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*t;
	char	ch;

	if (!s)
		return (NULL);
	ch = (char)c;
	i = 0;
	t = (char *)s;
	while (i < n)
	{
		if (*(t + i) == ch)
			return ((void *)t + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int s[] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%p\n%p\n", ft_memchr(s, 0, 1), memchr(s, 0, 1));
}*/
