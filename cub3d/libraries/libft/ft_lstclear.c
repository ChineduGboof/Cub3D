/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:02:29 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/14 15:49:52 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*traversing_pointer;

	if (lst == NULL || del == NULL)
		return ;
	while ((*lst) != NULL)
	{
		traversing_pointer = (*lst);
		(*lst) = (*lst)->next;
		ft_lstdelone(traversing_pointer, del);
	}
}
