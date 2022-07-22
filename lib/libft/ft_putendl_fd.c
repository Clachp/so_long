/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:58:42 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/24 13:05:28 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write (fd, &*s++, 1);
	write (fd, "\n", 1);
}
/*
int	main(void)
{
	char s[] = "une string";
	ft_putendl_fd(s, 1);
}*/
