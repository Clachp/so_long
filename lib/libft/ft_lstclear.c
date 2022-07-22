/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:59:00 by cchapon           #+#    #+#             */
/*   Updated: 2022/05/20 15:23:49 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*first;
	t_list	*temp;

	if (!lst || !del)
		return ;
	first = *lst;
	while (first != 0)
	{
		del(first->content);
		temp = first->next;
		free(first);
		first = temp;
	}
	*lst = NULL;
}
