/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:41:01 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 11:35:10 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	dst_len_save;
	size_t	i;

	if (dst == NULL || src == NULL)
		return (0);
	dst_len = ft_strlen(dst);
	dst_len_save = dst_len;
	i = 0;
	if (dst_len >= size)
		return (ft_strlen(src) + size);
	while (src[i] && dst_len < size - 1)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (dst_len_save + ft_strlen(src));
}
