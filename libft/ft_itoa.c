/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:58:07 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/24 13:03:49 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long long n)
{
	int	l;

	l = 1;
	while (n / 10)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static void	putnbr(long n, char *s, int i)
{	
	if (n >= 0 && n <= 9)
		s[i - 1] = n + '0';
	else
	{
		putnbr(n / 10, s, i - 1);
		putnbr(n % 10, s, i);
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		l;
	int		sign;
	long	nb;

	nb = n;
	l = int_len(n);
	sign = 0;
	if (n < 0)
		sign = 1;
	s = malloc(sizeof(char) * (l + 1 + sign));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		*s = '-';
		nb = -nb;
	}
	putnbr(nb, s + sign, l);
	*(s + l + sign) = '\0';
	return (s);
}
/*
int	main(void)
{
	int	n = 22;
	printf("int : %d\nft_itoa : %s\n", n, ft_itoa(n));
	printf("\n");
	//printf("INT_MAX : %d\nitoa : %s\n", INT_MAX, itoa(INT_MAX));
	return (0);
}*/
