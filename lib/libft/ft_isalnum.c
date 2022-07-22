/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:17:22 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/23 11:42:05 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || \
		(c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
int	main (void)
{
	int	c;
	c = 'X';
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));
}*/
