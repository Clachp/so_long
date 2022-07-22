/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:28:30 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/24 12:59:47 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	r;

	if (nptr == NULL)
		return (0);
	i = 0;
	s = 1;
	r = 0;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = -s;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (s * r);
}
/*
int	main(void)
{
	char *s = "-2147483647 - 1";
	printf ("atoi : %d\nft_atoi : %d\n", atoi(s), ft_atoi(s));
}*/
