/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:47:42 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/24 13:05:46 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || fd > 1024)
		return ;
	while (s && *s)
		write (fd, &*s++, 1);
}
/*
int	main(void)
{
	char s[] = "string";
	ft_putstr_fd(s, 1);
}*/
