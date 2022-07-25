/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:24:16 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 15:55:09 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dest || !src)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
				d[i] = s[i];
				i++;
		}			
	}
	else
	{
		i = n;
		while (i--)
			d[i] = s[i];
	}
	return (dest);
}
