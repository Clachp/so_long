/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:29:56 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 15:56:43 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big != NULL || little != NULL)
	{
		if (*little == '\0')
			return ((char *)big);
		i = 0;
		while (big[i] && i < len)
		{
			j = 0;
			while (little[j] && big[i + j] == little[j] && i + j < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
			i++;
		}
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *largestring = "aaabcabcd";
	const char *smallstring = "cd";
	char *ptr;
	char *ft_ptr;

	ptr = strnstr(largestring, smallstring, 0);
	ft_ptr = ft_strnstr(largestring, smallstring, 0);
	printf("largestring : %s\nsmallstring  : %s\n", largestring, smallstring);
	printf("strnstr : %s\nft_strnstr : %s\n", ptr, ft_ptr);
}*/
