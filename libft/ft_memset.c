/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:21:07 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 11:41:25 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = s;
	i = 0;
	while (i < n)
		ptr[i++] = c;
	return (s);
}
/*
int	main(void)
{
	char s[] = "string";
	printf("%s\n",(char *)memset(s, 1, 3));
	printf("%s\n",(char *)ft_memset(s, 1, 3));
}*/
